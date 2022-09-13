#ifndef _RULE_ENGINE_H
#define _RULE_ENGINE_H

#include <memory>
#include <boost/filesystem.hpp>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include "common/common.h"
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace edrs 
{
    class RuleEngine{
    public:
        RuleEngine();
        ~RuleEngine() = default;

        void analysis(const std::string logEntry) const;

    public:
        std::vector<boost::filesystem::path> findRuleFiles(const std::string) const;
        void initRuleset();

    private:
        std::unordered_map<std::string, std::list<RuleInfoStruct>>   mRuleset;
        
        std::vector<std::pair<std::string, std::string>> readXmlNodeProperties(const xmlNodePtr node) const;
        bool readRule(const xmlNodePtr node, RuleInfoStruct& rule) const;
        bool readRuleFields(const xmlNodePtr node, RuleInfoStruct& rule) const;
        uint32_t readRuleFieldIfMatched(const xmlNodePtr node) const;
        std::string readRuleFieldText(const xmlNodePtr node) const;
        std::string readRuleFieldMitre(const xmlNodePtr node) const;
        RuleFieldsCode str2enum(const std::string& str) const;
        std::string xmlChar2Str(const xmlChar* str) const;
        bool insertRule(std::list<RuleInfoStruct>& ruleList, RuleInfoStruct& rule) const;
        bool insertChildRule(std::vector<std::unique_ptr<RuleInfoStruct>>& children, RuleInfoStruct& rule) const;

        void testRule();
        void testRuleChild(std::unique_ptr<RuleInfoStruct> list, int n);
        void teststar(int n);
    };
} // namespace edrs

#endif // _RULE_ENGINE_H