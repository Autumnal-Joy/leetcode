cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SUBDIRECTORIES RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)

# 遍历每个子目录
foreach (SUBDIR ${SUBDIRECTORIES})
    # 检查是否存在 main.cpp 文件
    if (EXISTS ${CMAKE_SOURCE_DIR}/${SUBDIR}/main.cpp)
        # 设置可执行文件的名称为子目录名称
        add_executable(${SUBDIR} ${CMAKE_SOURCE_DIR}/${SUBDIR}/main.cpp)
    endif ()
endforeach ()

if (EXISTS ${CMAKE_SOURCE_DIR}/test.cpp)
    add_executable(test test.cpp)
endif ()
