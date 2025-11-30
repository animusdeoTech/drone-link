cmake_minimum_required(VERSION 3.20)
project(drone_link LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(px4_link)
add_subdirectory(lora_link)

