cmake_minimum_required(VERSION 3.1)
project(parallel-plates LANGUAGES CXX)
add_executable(ParallelPlates ParallelPlates.cpp)
set_property(TARGET ParallelPlates PROPERTY CXX_STANDARD 11)

add_executable(Pow Pow.cpp)
set_property(TARGET Pow PROPERTY CXX_STANDARD 11)
