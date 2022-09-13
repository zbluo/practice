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

//#include "openssl_test.h"
//#include "test1.h"

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
#include <openssl/bio.h>
#include <openssl/evp.h>

#include "rule_engine/rule_engine.h"
#include "common/common.h"

extern "C" {
#include "string_search_algo/match.h"
}

namespace string_search_algo{

using namespace std;
using namespace boost::filesystem;
using namespace boost::interprocess;
using namespace Json;

int test(int argc, const char **argv) {
    int ret;
    struct nfa *nfa = nfa_init();
    ret = nfa_add_pattern(nfa, reinterpret_cast<const unsigned char*>(argv[1]), strlen(argv[1]), NULL, NULL);
    printf("add(), ret=[%d].\n", ret);
    ret = nfa_add_pattern(nfa, reinterpret_cast<const unsigned char*>(argv[2]), strlen(argv[2]), NULL, NULL);
    printf("add(), ret=[%d].\n", ret);
    ret = nfa_compile(nfa);
    printf("compile(), ret=[%d].\n", ret);
    ret = nfa_find(nfa, reinterpret_cast<const unsigned char*>(argv[3]), strlen(argv[3]), NULL);
    printf("find(), ret=[%d].\n", ret);
    nfa_destroy(nfa);

    return 0;
}

}