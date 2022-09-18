cmake_minimum_required(VERSION 3.15)
project(SDL_Env_Test)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_DIR C:/mingw64)

# 设置要包含的头文件的路径
include_directories(${SDL2_DIR}/include)

# 设置要关联的库的路径
link_directories(${SDL2_DIR}/bin)

add_executable(SDL_Env_Test main.cpp)
target_link_libraries(SDL_Env_Test mingw32 SDL2 SDL2main)

