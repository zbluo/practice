#ifndef _COMMON_H
#define _COMMON_H
#include <string>

namespace edrs {
    static const char* RULESET_DIR = "/Volumes/workspace/lzb/practice/cpptest/ruleset/rules";
    static const std::string RULENODE_NAME          = "rule";
    static const std::string RULENODE_RULEID        = "id";
    static const std::string RULENODE_LEVEL         = "level";
    static const std::string RULENODE_FREQUENCY     = "frequency";
    static const std::string RULENODE_TIMEFRAME     = "timeframe";
    static const std::string RULENODE_IGNORE        = "ignore";
    static const std::string RULENODE_IFMATCHED     = "if_matched_sid";
    static const std::string RULENODE_SAMESOURCE    = "same_source_ip";
    static const std::string RULENODE_MATCH         = "match";
    static const std::string RULENODE_DESCRIPTION   = "description";
    static const std::string RULENODE_MITREID       = "mitre";

    struct LogEntryStruct {
        std::string         time;
        std::string         hostName;
        std::string         appName;
        std::string         message;
        bool                valid;
        LogEntryStruct() : valid(false) {}
    };

    struct EventStruct {
        uint32_t            level;
        uint32_t            ruleID;
        std::string         eventDescription;
        LogEntryStruct      logEntry;
        bool                hit;
        EventStruct() : hit(false) {}
    };

    struct RuleInfoStruct {
        uint32_t            ruleid;
        uint32_t            parentRuleId;
        uint16_t            level;
        uint16_t            frequency;
        uint16_t            timeframe;
        uint16_t            ignore;
        bool                sameSource;
        std::string         match;
        std::string         description;
        std::string         mitreid;

        std::vector<std::unique_ptr<RuleInfoStruct>>     children;
        RuleInfoStruct() :  ruleid(0),
                            parentRuleId(0),
                            level(0),
                            frequency(0),
                            timeframe(0),
                            ignore(0),
                            sameSource(false),
                            match(""),
                            description(""),
                            mitreid("") {}
        };

enum RuleFieldsCode {
    eRuleId,
    eLevel,
    eFrequency,
    eTimeframe,
    eIgnore,
    eIfMatched,
    eSameSource,
    eMatch,
    eDescription,
    eMitreid,
    eUnknownRuleField
};
}
#endif // _COMMON_H
