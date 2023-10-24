cmake_minimum_required(VERSION 3.1...3.14)

# crctest
add_executable(crctest crctest.cpp)
target_link_libraries(crctest gtest gtest_main)
add_test(NAME crctest COMMAND crctest)
set_target_properties(crctest PROPERTIES FOLDER test)
