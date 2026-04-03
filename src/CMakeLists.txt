cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #for the nvim lsp see cmake 

find_package(raylib REQUIRED)

add_executable(SpaceInvaders main.cpp Player/player.cpp Entity/entity.cpp Bullet/bullet.cpp Invader/invader.cpp InvadersController/invadersController.cpp BulletsController/bulletsController.cpp TimedBulletsController/timedBulletsController.cpp GameController/gameController.cpp UIController/uiController.cpp SoundController/soundController.cpp Ufo/ufo.cpp)

target_include_directories(SpaceInvaders PRIVATE .) 

target_link_libraries(SpaceInvaders raylib)

