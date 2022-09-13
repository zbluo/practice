#include <iostream>

#include "rule_engine.h"

namespace edrs
{
    namespace fs = boost::filesystem;
    RuleEngine::RuleEngine() {

    }

    /**
     * @brief Find all rule files under a specific directory.
     *        This API doesn't check whether the rule file is valid or not, and
     *        it assumes all files under this directory are rule files.
     * 
     * @param rulesetDir 
     * @return std::vector<fs::path> 
     */
    std::vector<fs::path> RuleEngine::findRuleFiles(const std::string dir) const {
        std::vector<fs::path> ruleFiles;
        fs::path p (dir);
        fs::directory_iterator end_itr;

        // cycle through the directory
        for (fs::directory_iterator itr(p); itr != end_itr; ++itr)
        {
            // If it's a file, add it to the result.
            if (is_regular_file(itr->path())) {
                ruleFiles.push_back(itr->path());
            }
        }
        
        return ruleFiles;
    }

static void
print_element_names(xmlNode * a_node, int dep)
{
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
            printf("dep: %d, node type: %d, name: %s \n", dep, cur_node->type, cur_node->name);

            if(cur_node->properties != nullptr) {
                for(auto cur_pro = cur_node->properties; cur_pro != nullptr; cur_pro = cur_pro->next) {
                    std::cout << "properties: " << cur_pro->name << std::endl;
                    std::cout << "properties content: " << cur_pro->children->content << std::endl;
                }
            }
            if(cur_node->type == XML_TEXT_NODE)
              std::cout << "content: " << cur_node->content << std::endl;
            else
              std::cout << std::endl;

        print_element_names(cur_node->children, dep * 10);
    }
}
    std::vector<std::pair<std::string, std::string>> RuleEngine::readXmlNodeProperties(const xmlNodePtr node) const {
        std::vector<std::pair<std::string, std::string>> xmlNodeProperties;
        if(node == nullptr)
            return xmlNodeProperties;
        for(auto cur = node->properties; cur != nullptr; cur = cur->next) {
            std::pair<std::string, std::string> property;
            property.first += reinterpret_cast<const char*>(cur->name);
            if(cur->children != nullptr)
                property.second += reinterpret_cast<char*>(cur->children->content);
            else 
                std::cout << "empty property" << std::endl;
            xmlNodeProperties.push_back(property); 
        }
        return xmlNodeProperties;
    }

    std::string RuleEngine::xmlChar2Str(const xmlChar* str) const {
        const std::string tmp(reinterpret_cast<const char*>(str));
        return tmp;
    }

    bool RuleEngine::readRule(const xmlNodePtr node, RuleInfoStruct& rule) const {
        if(xmlChar2Str(node->name) != RULENODE_NAME) {
            std::cout << "Invalide rule node name" << std::endl;
            return false;
        }

        auto ruleProperties = readXmlNodeProperties(node);
        for(auto it = ruleProperties.begin(); it != ruleProperties.end(); it++) {
            switch(str2enum(it->first)) {
            case eRuleId:
                rule.ruleid = stoi(it->second);
                break;
            case eLevel:
                rule.level = stoi(it->second);
                break;
            case eFrequency:
                rule.frequency = stoi(it->second);
                break;
            case eTimeframe:
                rule.timeframe = stoi(it->second);
                break;
            case eIgnore:
                rule.ignore = stoi(it->second);
                break;
            default:
                break;
            }
        }

        return readRuleFields(node->children, rule);
    }

    bool RuleEngine::readRuleFields(const xmlNodePtr node, RuleInfoStruct& rule) const {
        for(auto cur = node; cur != nullptr; cur = cur->next) {
            switch(str2enum(xmlChar2Str(cur->name))) {
            case eIfMatched:
                rule.parentRuleId = readRuleFieldIfMatched(cur->children);
                break;
            case eSameSource:
                rule.sameSource = true;
                break;
            case eMatch:
                rule.match = readRuleFieldText(cur->children);
                break;
            case eDescription:
                rule.description = readRuleFieldText(cur->children);
                break;
            case eMitreid:
                rule.mitreid = readRuleFieldMitre(cur->children);
                break;
            default:
                break;
            }
        }

        return true;
    }

    uint32_t RuleEngine::readRuleFieldIfMatched(const xmlNodePtr node) const {
        if(node == nullptr)
            return 0;
        return stoi(xmlChar2Str(node->content));
    }

    std::string RuleEngine::readRuleFieldText(const xmlNodePtr node) const {
        if(node == nullptr)
            return "";
        return xmlChar2Str(node->content);
    }

    std::string RuleEngine::readRuleFieldMitre(const xmlNodePtr node) const {
        for(auto cur = node; cur != nullptr; cur = cur->next) {
            if(xmlChar2Str(cur->name) == RULENODE_RULEID)
                return readRuleFieldText(cur->children);
        }

        return "";
    }

    RuleFieldsCode RuleEngine::str2enum(const std::string& str) const {
        if(str == RULENODE_RULEID)          return eRuleId;
        if(str == RULENODE_LEVEL)           return eLevel;
        if(str == RULENODE_FREQUENCY)       return eFrequency;
        if(str == RULENODE_TIMEFRAME)       return eTimeframe;
        if(str == RULENODE_IGNORE)          return eIgnore;
        if(str == RULENODE_IFMATCHED)       return eIfMatched;
        if(str == RULENODE_SAMESOURCE)      return eSameSource;
        if(str == RULENODE_MATCH)           return eMatch;
        if(str == RULENODE_DESCRIPTION)     return eDescription;
        if(str == RULENODE_MITREID)         return eMitreid;
        return eUnknownRuleField;
    }

    bool RuleEngine::insertRule(std::list<RuleInfoStruct>& ruleList, RuleInfoStruct& rule) const {
        if(rule.parentRuleId == 0) {
            ruleList.push_back(std::move(rule));
            return true;
        }

        for(auto it = ruleList.begin(); it != ruleList.end(); it++) {
            if(it->ruleid == rule.parentRuleId) {
                it->children.push_back(std::make_unique<RuleInfoStruct>(std::move(rule)));
                return true;
            }
            if(it->children.empty() == false) {
                if(insertChildRule(it->children, rule))
                    return true;
            }
        }

        return false;
    }

    bool RuleEngine::insertChildRule(std::vector<std::unique_ptr<RuleInfoStruct>>& children, RuleInfoStruct& rule) const {
        if(children.empty())
            return false;
        for(auto& child : children) {
            if(child->ruleid == rule.parentRuleId) {
                child->children.push_back(std::make_unique<RuleInfoStruct>(std::move(rule)));
                return true;
            }
            if(child->children.empty() == false) {
                if(insertChildRule(child->children, rule))
                    return true;
            }
        }

        return false;
    }

    void RuleEngine::initRuleset() {
        auto ruleFiles = findRuleFiles(RULESET_DIR);
        for(auto rf : ruleFiles) {
            xmlDocPtr   xmldoc;
            xmlNodePtr  rootXmlNode;

            xmldoc = xmlReadFile(rf.c_str(), NULL, 0);
            if(xmldoc == nullptr) {
                std::cout << "Null XML file: " << rf.c_str() << std::endl;
                return;
            }

            rootXmlNode = xmlDocGetRootElement(xmldoc);
            std::cout << "XML file: " << rf.c_str() << std::endl;

            auto rootProperties = readXmlNodeProperties(rootXmlNode);

            std::list<RuleInfoStruct> ruleList;
            for(auto ruleNode = rootXmlNode->children; ruleNode != nullptr; ruleNode = ruleNode->next) {
                RuleInfoStruct rule;
                if(readRule(ruleNode, rule)) {
                    if(insertRule(ruleList, rule) == false) {
                        std::cout << "Invalid rule" << std::endl;
                    }
                }
            }

            mRuleset[rootProperties.front().second] = std::move(ruleList);

            //print_element_names(rootXmlNode->children, 1);

            xmlFreeDoc(xmldoc);

            /**
             * Free the global variables that may
             * have been allocated by the parser.
             */
            xmlCleanupParser();
            std::cout << "End of XML file: " << rf.c_str() << std::endl;
            std::cout << "**********************************" << std::endl;
        }
        testRule();
    }

    void RuleEngine::testRule() {
        std::cout << "mRuleset size: " << mRuleset.size() << std::endl;

        for(auto it = mRuleset.begin(); it != mRuleset.end(); it++) {
            std::cout << "*********************************************************************" << std::endl;
            std::cout << "group: " << it->first.c_str() << std::endl;
            for(auto list = it->second.begin(); list != it->second.end(); list++) {
                std::cout << "ruleid: " << list->ruleid << std::endl;
                std::cout << "parentRuleId: " << list->parentRuleId << std::endl;
                std::cout << "level: " << list->level << std::endl;
                std::cout << "frequency: " << list->frequency << std::endl;
                std::cout << "timeframe: " << list->timeframe << std::endl;
                std::cout << "ignore: " << list->ignore << std::endl;
                std::cout << "sameSource: " << list->sameSource << std::endl;
                std::cout << "match: " << list->match.c_str() << std::endl;
                std::cout << "description: " << list->description.c_str() << std::endl;
                std::cout << "mitreid: " << list->mitreid.c_str() << std::endl;
                std::cout << std::endl;
                for(auto it = list->children.begin(); it != list->children.end(); it++)
                    testRuleChild(std::move(*it), 2);
            }
        }
        return;
    }

    void RuleEngine::testRuleChild(std::unique_ptr<RuleInfoStruct> list, int n) {
                teststar(n);
                std::cout << "ruleid: " << list->ruleid << std::endl;
                teststar(n);
                std::cout << "parentRuleId: " << list->parentRuleId << std::endl;
                teststar(n);
                std::cout << "level: " << list->level << std::endl;
                teststar(n);
                std::cout << "frequency: " << list->frequency << std::endl;
                teststar(n);
                std::cout << "timeframe: " << list->timeframe << std::endl;
                teststar(n);
                std::cout << "ignore: " << list->ignore << std::endl;
                teststar(n);
                std::cout << "sameSource: " << list->sameSource << std::endl;
                teststar(n);
                std::cout << "match: " << list->match.c_str() << std::endl;
                teststar(n);
                std::cout << "description: " << list->description.c_str() << std::endl;
                teststar(n);
                std::cout << "mitreid: " << list->mitreid.c_str() << std::endl;
                std::cout << std::endl;
                for(auto it = list->children.begin(); it != list->children.end(); it++)
                    testRuleChild(std::move(*it), n * 2);
    }
    void RuleEngine::teststar(int n) {
        for(int i = 0; i < n; i++)
            std::cout << "*";
    }
} // namespace edrs