cmake_minimum_required(VERSION 3.24)

project(xanel2)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_VERSION 5.5)
set(BUILD_EXAMPLES OFF)
set(raylib_USE_STATIC_LIBS ON)
set(BUILD_SHARED_LIBS OFF)
set(GLFW_BUILD_WAYLAND ON)
set(PLATFORM Desktop)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG ${RAYLIB_VERSION}
)

FetchContent_MakeAvailable(raylib)

set(FILE_IN src/main.cpp src/game.cpp src/object.cpp src/player.cpp)

add_executable(${PROJECT_NAME} ${FILE_IN})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)
