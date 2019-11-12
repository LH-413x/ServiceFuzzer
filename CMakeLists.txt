cmake_minimum_required(VERSION 3.14)
project(AOSP_Service_Fuzzer)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(befuzzed)
add_subdirectory(libfuzzer)
add_subdirectory(service)