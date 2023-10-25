cmake_minimum_required(VERSION 3.1...3.14)

# Adding modules to be linked either by the application
add_library(libcrc crc.cpp ../include/crc/crc.h)
target_include_directories(libcrc PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_sources(libcrc PRIVATE crc.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include/crc/crc.h)