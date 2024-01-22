cmake_minimum_required(VERSION 3.20)
project(OmniviewXXEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# find_package(Threads REQUIRED)

# add_executable(my_app main.cpp)
# target_link_libraries(my_app PRIVATE Threads::Threads)

# 构建工作空间
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Hazelnut)
#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY SOLUTION_ITEMS ".editorconfig")

# 设置构建目标
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/${CMAKE_BUILD_TYPE}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}/${CMAKE_BUILD_TYPE}/lib")

# 添加子目录
add_subdirectory(OmniviewXEngine/3rdparty/spdlog)
add_subdirectory(OmniviewXEngine/3rdparty/Glad)
add_subdirectory(OmniviewXEngine/3rdparty/GLFW)
add_subdirectory(OmniviewXEngine/3rdparty/imgui)
add_subdirectory(OmniviewXEngine/3rdparty/yaml-cpp)
# add_subdirectory(Appbox)
add_subdirectory(OmniviewXEngineInput)
add_subdirectory(OmniviewXEngine)



