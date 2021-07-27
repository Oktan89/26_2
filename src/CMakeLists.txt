cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp)

add_executable(Phone ${SOURCES})

target_include_directories(Phone PUBLIC ${MY_INCLUDE_DIR})