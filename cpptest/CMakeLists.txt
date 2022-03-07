cmake_minimum_required(VERSION 3.17)
project(cpptest)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/opt/openssl@1.1/include)
# include_directories(/usr/local/opt/boost/include)
include_directories(./include)
link_directories(/usr/local/Cellar/openssl@1.1/1.1.1m/lib)

#find_package(Boost 1.58.0 REQUIRED
#        COMPONENTS
#        system
#        filesystem)
#link_directories(${Boost_LIBRARY_DIRS})

add_executable(cpptest main.cpp openssl_test.c include/test1.h)

#find_library(OpenSSL REQUIRED)
set( OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1")
find_package(OpenSSL REQUIRED)

target_link_libraries(cpptest ssl crypto)

