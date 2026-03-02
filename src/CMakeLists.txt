cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

# Use C++17 for modern features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Find the raylib package on your system
find_package(raylib REQUIRED)

# 2. Tell CMake which file is your "starting point"
add_executable(SpaceInvaders main.cpp Player/player.cpp)

# 3. Link the raylib library to your executable
target_link_libraries(SpaceInvaders raylib)
