cmake_minimum_required(VERSION 3.20)
project(Appbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


include_directories(
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/spdlog/include"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/src"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/Glad"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/GLFW"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/glm"
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/3rdparty/imgui")

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.h")

add_definitions("-Wall -g")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/OmniviewXEngine/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE "-Wl,--whole-archive" OmniviewXEngine "-Wl,--no-whole-archive")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
