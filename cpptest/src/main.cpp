// git: ssh-add ~/.ssh/id_ed25519_zbluo_gitlab_personal
#include <boost/filesystem.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <chrono>
#include <exception>
#include <future>
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <iomanip>
#include <json/json.h>
#include <map>
#include <math.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <pthread.h>
#include <queue>
#include <unordered_map>
#include <regex>
#include <sys/mman.h>
#include <set>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <unordered_set>
#include <unistd.h>
#include <vector>

#include "common/common.h"

#include "string_search_algo/test.h"
#include "socket_test/socket_test.h"

int main(int argc, const char **argv) {
    try {
        std::string dir = "no dir";
        throw std::runtime_error("my errors" + dir);
        throw "hi";
    } catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
    } catch(...) {
        std::cout << "other exception" << std::endl;
    }
    return 0;
}