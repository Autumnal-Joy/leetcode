cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach (SUBDIR ${SUBDIRECTORIES})
    if (EXISTS ${CMAKE_SOURCE_DIR}/${SUBDIR}/main.cpp)
        add_executable(${SUBDIR} ${CMAKE_SOURCE_DIR}/${SUBDIR}/main.cpp)
    endif ()
endforeach ()

file(GLOB TESTFILES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/test*.cpp)
foreach (TESTFILE ${TESTFILES})
    get_filename_component(NAME_WITHOUT_EXT ${TESTFILE} NAME_WE)
    add_executable(${NAME_WITHOUT_EXT} ${CMAKE_SOURCE_DIR}/${NAME_WITHOUT_EXT}.cpp)
endforeach ()
