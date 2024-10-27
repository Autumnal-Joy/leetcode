cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MAIN_CPP_FILES "*/main.cpp")
foreach(MAIN_CPP_FILE ${MAIN_CPP_FILES})
    get_filename_component(DIR ${MAIN_CPP_FILE} DIRECTORY)
    get_filename_component(TARGET_NAME ${DIR} NAME)
    add_executable(${TARGET_NAME} ${MAIN_CPP_FILE})
endforeach()

file(GLOB TESTFILES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/test*.cpp)
foreach (TESTFILE ${TESTFILES})
    get_filename_component(NAME_WITHOUT_EXT ${TESTFILE} NAME_WE)
    add_executable(${NAME_WITHOUT_EXT} ${CMAKE_SOURCE_DIR}/${NAME_WITHOUT_EXT}.cpp)
endforeach ()
