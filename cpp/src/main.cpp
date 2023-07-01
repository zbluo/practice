// git: ssh-add ~/.ssh/id_ed25519_zbluo_gitlab_personal
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <chrono>
#include <csignal>
#include <exception>
#include <future>
#include <fstream>
#include <fcntl.h>
#include <iostream>
#include <iomanip>
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
#include <json/json.h>

#include "socket_test/socket_test.h"
#include "posix_semaphore/test.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // #include "string_search_algo/match.h"

#ifdef __cplusplus
}
#endif

int main(int argc, const char **argv)
{
    std::cout << "Test start......" << std::endl;
    return 0;
}