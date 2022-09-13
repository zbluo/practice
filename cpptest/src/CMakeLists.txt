set( OPENSSL_ROOT_DIR "/usr/local/opt/openssl@1.1")
find_package(OpenSSL REQUIRED)

find_package(Boost 1.58.0 REQUIRED
        COMPONENTS
        system
        filesystem)

find_package(LibXml2 REQUIRED)
add_library(jsoncpp SHARED IMPORTED)
set_target_properties(jsoncpp PROPERTIES
        IMPORTED_LOCATION "/usr/local/lib/libjsoncpp.dylib"
)

# source files
FILE(GLOB_RECURSE CPPTEST_SRCS_CPP *.cpp)
set(PRJ_SRCS_CPP ${CPPTEST_SRCS_CPP})
FILE(GLOB_RECURSE CPPTEST_SRCS_C *.c)
set(PRJ_SRCS_C ${CPPTEST_SRCS_C})
# end of source files

# build
add_executable(
	${PRJ_NAME}
        ${PRJ_SRCS_CPP}
        ${PRJ_SRCS_C}
)
target_include_directories(${PRJ_NAME} 
        PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Boost_INCLUDE_DIR} 
        ${OPENSSL_INCLUDE_DIR} 
)
target_link_libraries(${PRJ_NAME} 
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        ${LIBXML2_LIBRARIES}
        jsoncpp
)

