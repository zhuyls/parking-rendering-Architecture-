cmake_minimum_required(VERSION 3.12)

project(ImGui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(outputdir "Debug")  # 设置默认的outputdir

# 设置平台相关的编译选项和宏定义
if(WIN32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# 设置输出目录和中间目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})

# 添加源文件
file(GLOB_RECURSE SOURCES
    imconfig.h
    imgui.h
    imgui.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    imgui_demo.cpp
)

# 创建静态库
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# 设置编译选项
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# 针对不同配置设置编译选项
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# 设置输出目录和中间目录的位置
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
)

# 针对Debug配置设置链接库和符号选项
if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_link_libraries(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
endif()

# 针对Release配置设置优化选项
if(CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(${PROJECT_NAME} PRIVATE -O3)
endif()
