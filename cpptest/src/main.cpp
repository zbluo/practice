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
#include <openssl/bio.h>
#include <openssl/evp.h>
#include "common/common.h"

#include "string_search_algo/test.h"

using namespace std;
using namespace boost::filesystem;
using namespace boost::interprocess;
using namespace Json;

int main(int argc, const char **argv) {
    string_search_algo::test(argc, argv);
    return 0;
}