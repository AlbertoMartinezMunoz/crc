cmake_minimum_required(VERSION 3.1...3.14)

# crc8test
add_executable(crc8test crc8test.cpp)
target_link_libraries(crc8test gtest gtest_main crc)
add_test(NAME crc8test COMMAND crc8test)
set_target_properties(crc8test PROPERTIES FOLDER test)

# crc8cdma2000test
add_executable(crc8cdma2000test crc8cdma2000test.cpp)
target_link_libraries(crc8cdma2000test gtest gtest_main crc)
add_test(NAME crc8cdma2000test COMMAND crc8cdma2000test)
set_target_properties(crc8cdma2000test PROPERTIES FOLDER test)

# crc16usbtest
add_executable(crc16usbtest crc16usbtest.cpp)
target_link_libraries(crc16usbtest gtest gtest_main crc)
add_test(NAME crc16usbtest COMMAND crc16usbtest)
set_target_properties(crc16usbtest PROPERTIES FOLDER test)

# crc32test
add_executable(crc32test crc32test.cpp)
target_link_libraries(crc32test gtest gtest_main crc)
add_test(NAME crc32test COMMAND crc32test)
set_target_properties(crc32test PROPERTIES FOLDER test)
