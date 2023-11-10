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

# crc8darctest
add_executable(crc8darctest crc8darctest.cpp)
target_link_libraries(crc8darctest gtest gtest_main crc)
add_test(NAME crc8darctest COMMAND crc8darctest)
set_target_properties(crc8darctest PROPERTIES FOLDER test)

# crc8dvbs2test
add_executable(crc8dvbs2test crc8dvbs2test.cpp)
target_link_libraries(crc8dvbs2test gtest gtest_main crc)
add_test(NAME crc8dvbs2test COMMAND crc8dvbs2test)
set_target_properties(crc8dvbs2test PROPERTIES FOLDER test)

# crc8ebutest
add_executable(crc8ebutest crc8ebutest.cpp)
target_link_libraries(crc8ebutest gtest gtest_main crc)
add_test(NAME crc8ebutest COMMAND crc8ebutest)
set_target_properties(crc8ebutest PROPERTIES FOLDER test)

# crc8icodetest
add_executable(crc8icodetest crc8icodetest.cpp)
target_link_libraries(crc8icodetest gtest gtest_main crc)
add_test(NAME crc8icodetest COMMAND crc8icodetest)
set_target_properties(crc8icodetest PROPERTIES FOLDER test)

# crc8itutest
add_executable(crc8itutest crc8itutest.cpp)
target_link_libraries(crc8itutest gtest gtest_main crc)
add_test(NAME crc8itutest COMMAND crc8itutest)
set_target_properties(crc8itutest PROPERTIES FOLDER test)

# crc8maximtest
add_executable(crc8maximtest crc8maximtest.cpp)
target_link_libraries(crc8maximtest gtest gtest_main crc)
add_test(NAME crc8maximtest COMMAND crc8maximtest)
set_target_properties(crc8maximtest PROPERTIES FOLDER test)

# crc8rohctest
add_executable(crc8rohctest crc8rohctest.cpp)
target_link_libraries(crc8rohctest gtest gtest_main crc)
add_test(NAME crc8rohctest COMMAND crc8rohctest)
set_target_properties(crc8rohctest PROPERTIES FOLDER test)

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
