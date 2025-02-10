set( OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@1.1")
# find_package(OpenSSL REQUIRED)

#find_package(Boost 1.58.0 REQUIRED
#        COMPONENTS
#        system
#        filesystem)

#find_package(LibXml2 REQUIRED)
#find_package(yaml-cpp REQUIRED)
#find_package(CURL REQUIRED)

if(APPLE)
    message(STATUS "Building on macOS")
#    find_package(jsoncpp REQUIRED)
else()
    message(STATUS "Building on non-macOS platform")
#    find_package(PkgConfig REQUIRED)
#    pkg_check_modules(JSONCPP REQUIRED jsoncpp)
endif()

# source files
FILE(GLOB_RECURSE CPPTEST_SRCS_CPP *.cpp)
set(PRJ_SRCS_CPP ${CPPTEST_SRCS_CPP})
FILE(GLOB_RECURSE CPPTEST_SRCS_C *.c)
set(PRJ_SRCS_C ${CPPTEST_SRCS_C})
# end of source files
# header files
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(HEADER_DIR_LIST)
# end of header files

# build
add_executable(
	${PRJ_NAME}
        ${PRJ_SRCS_CPP}
        ${PRJ_SRCS_C}
)
target_include_directories(${PRJ_NAME} 
        PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
        ${HEADER_DIR_LIST}
        ${CMAKE_CURRENT_SOURCE_DIR}
#        ${Boost_INCLUDE_DIR} 
#        ${OPENSSL_INCLUDE_DIR} 
#        ${LIBXML2_INCLUDE_DIRS}
#        ${JSONCPP_INCLUDE_DIRS}
#        ${YAML_INCLUDE_DIRS}
#        ${CURL_INCLUDE_DIRS}
)

target_link_libraries(${PRJ_NAME} 
#        ${Boost_LIBRARIES}
#        ${OPENSSL_LIBRARIES}
#        ${LIBXML2_LIBRARIES}
#        ${JSONCPP_LIBRARIES}
#        ${YAML_CPP_LIBRARIES}
#        ${CURL_LIBRARIES}
    )

