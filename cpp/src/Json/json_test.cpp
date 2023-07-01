#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <queue>
#include <future>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <chrono>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>
#include <sys/mman.h>
#include <regex>
#include <json/json.h>

#include "json_test.h"
using namespace std;
using namespace boost::filesystem;
using namespace boost::interprocess;
using namespace Json;

int json()
{
    std::string strJson = R"({"foo": "bar", "logLevel": "debug", "logSource":[{"source": "syslog"},{"source":"kernellog"}]})";
    std::string subJson = R"([{"source": "syslog"},{"source":"kernellog"}])";

    Json::CharReaderBuilder builder;
    Json::CharReader *reader = builder.newCharReader();

    Json::Value json;
    std::string errors;

    bool parsingSuccessful = reader->parse(
        strJson.c_str(),
        strJson.c_str() + strJson.size(),
        &json,
        &errors);
    delete reader;

    if (!parsingSuccessful)
    {
        std::cout << "Failed to parse the JSON, errors:" << std::endl;
        std::cout << errors << std::endl;
        return 0;
    }

    std::cout << json.get("foo", "default value").asString() << std::endl;
    std::cout << json.get("logLevel", "default value").asString() << std::endl;
    std::cout << json["logSource"][0].get("source1", "default value1").asString() << std::endl;

    Json::Value event;

    event["compe titors"] = "Liverpool";
    event["away"] = 89223;
    event["name"] = "Aston Villa";
    // std::cout << event << std::endl;
    ostringstream os;
    StreamWriterBuilder builder1;
    builder1["commentStyle"] = "None";
    builder1["indentation"] = ""; // or whatever you like
    std::unique_ptr<Json::StreamWriter> writer(builder1.newStreamWriter());
    writer->write(event, &os);
    cout << os.str().c_str();
    std::cout << std::endl; // add lf and flush
    return 0;
}