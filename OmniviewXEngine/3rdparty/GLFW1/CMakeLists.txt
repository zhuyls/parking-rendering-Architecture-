cmake_minimum_required(VERSION 3.20)
project(GLFW)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES 
    include/GLFW/glfw3.h
    include/GLFW/glfw3native.h
    src/context.c
    src/init.c
    src/input.c
    src/monitor.c
    src/vulkan.c
    src/window.c
)


list(APPEND SOURCE_FILES 
    src/x11_init.c
    src/x11_monitor.c
    src/x11_window.c
    src/xkb_unicode.c
    src/posix_time.c
    src/posix_thread.c
    src/glx_context.c
    src/egl_context.c
    src/osmesa_context.c
    src/linux_joystick.c
)

add_definitions(-D_GLFW_X11)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${outputdir}/${PROJECT_NAME})

# set_target_properties(GLFW PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}
# )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(GLFW PRIVATE -g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(GLFW PRIVATE -O3)
endif()