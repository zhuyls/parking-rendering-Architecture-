cmake_minimum_required(VERSION 3.20)
project(Glad)

set(CMAKE_C_STANDARD 11)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})

# 添加源文件

file(GLOB_RECURSE SOURCES
    include/glad/glad.h
    include/KHR/khrplatform.h
    src/glad.c
)

# # 添加包含目录
include_directories(include)

# 添加目标
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# 设置编译选项
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")

# 设置配置
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

