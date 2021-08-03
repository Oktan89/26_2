cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp phone.cpp number.cpp ${MY_INCLUDE_DIR}/phone.h person.cpp ${MY_INCLUDE_DIR}/person.h ${MY_INCLUDE_DIR}/number.h)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Phone ${SOURCES})

target_include_directories(Phone PUBLIC ${MY_INCLUDE_DIR})