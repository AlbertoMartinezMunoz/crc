cmake_minimum_required(VERSION 3.1...3.14)

# crc8test
add_executable(crc8test crc8test.cpp)
target_link_libraries(crc8test gtest gtest_main crc)
add_test(NAME crc8test COMMAND crc8test)
set_target_properties(crc8test PROPERTIES FOLDER test)

# crc16usbtest
add_executable(crc16usbtest crc16usbtest.cpp)
target_link_libraries(crc16usbtest gtest gtest_main crc)
add_test(NAME crc16usbtest COMMAND crc16usbtest)
set_target_properties(crc16usbtest PROPERTIES FOLDER test)
