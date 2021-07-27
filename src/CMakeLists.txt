cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp  phone.cpp ${MY_INCLUDE_DIR}/phone.h  person.cpp ${MY_INCLUDE_DIR}/person.h )

add_executable(Phone ${SOURCES})

target_include_directories(Phone PUBLIC ${MY_INCLUDE_DIR})