# feito por: maquinzz
cmake_minimum_required(VERSION 3.16)
project(byte-diff-cpp VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_executable(byte-diff src/main.cpp src/diff.cpp)
target_include_directories(byte-diff PRIVATE include)
target_compile_options(byte-diff PRIVATE -Wall -Wextra -Wpedantic -Werror)
