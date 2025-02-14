cmake_minimum_required(VERSION 3.24)

project(Xanel2)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib
    GIT_TAG ${RAYLIB_VERSION}
)

FetchContent_MakeAvailable(raylib)

add_executable(xanel2 src/main.cpp src/game.cpp src/object.cpp)

target_link_libraries(xanel2 PRIVATE raylib)

target_include_directories(xanel2 PRIVATE ${raylib_SOURCE_DIR}/src)

# If Raylib does not automatically define the proper target, use:
# target_link_libraries(xanel2 PRIVATE ${raylib_LIBRARIES})
