cmake_minimum_required(VERSION 3.1...3.14)

# crctest
add_executable(crctest crctest.cpp)
target_link_libraries(crctest gtest gtest_main)
add_test(NAME crctest COMMAND crctest)
set_target_properties(crctest PROPERTIES FOLDER test)

# crc16usbtest
add_executable(crc16usbtest crc16usbtest.cpp)
target_link_libraries(crc16usbtest gtest gtest_main libcrc)
add_test(NAME crc16usbtest COMMAND crc16usbtest)
set_target_properties(crc16usbtest PROPERTIES FOLDER test)