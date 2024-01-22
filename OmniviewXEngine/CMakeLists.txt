cmake_minimum_required(VERSION 3.20)

project(OmniviewXEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

# 预编译头文件
set(PCH_HEADER "src/Omniviewpch.h")
set(PCH_SOURCE "src/Omniviewpch.cpp")

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE STB_IMAGE_SOURCES "3rdparty/stb_image/*.cpp" "3rdparty/stb_image/*.h")
file(GLOB_RECURSE GLM_HEADERS "3rdparty/glm/glm/*.hpp")
file(GLOB_RECURSE ENTT_HEADERS "3rdparty/entt/include/*.hpp")
file(GLOB_RECURSE GLM_INL_HEADERS "3rdparty/glm/glm/*.inl")
file(GLOB_RECURSE IMGAZMO_HEADERS "3rdparty/ImGuizmo/ImGuizmo.h")
file(GLOB_RECURSE IMGAZMO_SOURCES "3rdparty/ImGuizmo/ImGuizmo.cpp") 

list(APPEND SOURCE_FILES  ${STB_IMAGE_SOURCES} ${GLM_HEADERS} ${GLM_INL_HEADERS} ${ENTT_HEADERS} 
                          ${IMGAZMO_HEADERS} ${IMGAZMO_SOURCES}) 

# 静态库
add_library(${PROJECT_NAME} STATIC
    ${SOURCE_FILES}
    ${HEADER_FILES}
)


add_definitions(-DOMNIVIEW_DEBUG) 

add_definitions("-Wall -g")

# 预编译头
target_sources(${PROJECT_NAME} PRIVATE ${PCH_SOURCE})

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    "src"
    "3rdparty/spdlog/include"
    "3rdparty/GLFW/include"
    "3rdparty/Glad/include"
    "3rdparty/entt/include"
    "3rdparty/yaml-cpp"
    "3rdparty/glm"
    "3rdparty/imgui"
    "3rdparty/stb_image"
    "3rdparty/ImGuizmo"
)

# cmake_minimum_required(VERSION 3.20)

# project(OmniviewXEngine)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin-int/${CMAKE_BUILD_TYPE}/${PROJECT_NAME})

# set(HAZEL_SOURCE_FILES
#     src/*.h
#     src/*.cpp
#     3rdparty/stb_image/*.h
#     3rdparty/stb_image/*.cpp
#     3rdparty/glm/glm/*.hpp
#     3rdparty/glm/glm/*.inl
#     3rdparty/ImGuizmo/ImGuizmo.h
#     3rdparty/ImGuizmo/ImGuizmo.cpp
# )

# add_library(${PROJECT_NAME} STATIC ${HAZEL_SOURCE_FILES})

# target_compile_definitions(${PROJECT_NAME} PRIVATE _CRT_SECURE_NO_WARNINGS GLFW_INCLUDE_NONE)
# target_include_directories(${PROJECT_NAME} PRIVATE
#     src
#     3rdparty/spdlog/include
#     ${IncludeDir.Box2D}
#     ${IncludeDir.filewatch}
#     ${IncludeDir.GLFW}
#     ${IncludeDir.Glad}
#     ${IncludeDir.ImGui}
#     ${IncludeDir.glm}
#     ${IncludeDir.msdfgen}
#     ${IncludeDir.msdf_atlas_gen}
#     ${IncludeDir.stb_image}
#     ${IncludeDir.entt}
#     ${IncludeDir.mono}
#     ${IncludeDir.yaml_cpp}
#     ${IncludeDir.ImGuizmo}
#     ${IncludeDir.VulkanSDK}
# )

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    Glad
    ImGui
    yaml-cpp
    stdc++fs
)

