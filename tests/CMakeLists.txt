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

# crc8wcdmatest
add_executable(crc8wcdmatest crc8wcdmatest.cpp)
target_link_libraries(crc8wcdmatest gtest gtest_main crc)
add_test(NAME crc8wcdmatest COMMAND crc8wcdmatest)
set_target_properties(crc8wcdmatest PROPERTIES FOLDER test)

# crc16arctest
add_executable(crc16arctest crc16arctest.cpp)
target_link_libraries(crc16arctest gtest gtest_main crc)
add_test(NAME crc16arctest COMMAND crc16arctest)
set_target_properties(crc16arctest PROPERTIES FOLDER test)

# crc16augccitttest
add_executable(crc16augccitttest crc16augccitttest.cpp)
target_link_libraries(crc16augccitttest gtest gtest_main crc)
add_test(NAME crc16augccitttest COMMAND crc16augccitttest)
set_target_properties(crc16augccitttest PROPERTIES FOLDER test)

# crc16buypasstest
add_executable(crc16buypasstest crc16buypasstest.cpp)
target_link_libraries(crc16buypasstest gtest gtest_main crc)
add_test(NAME crc16buypasstest COMMAND crc16buypasstest)
set_target_properties(crc16buypasstest PROPERTIES FOLDER test)

# crc16ccittfalsetest
add_executable(crc16ccittfalsetest crc16ccittfalsetest.cpp)
target_link_libraries(crc16ccittfalsetest gtest gtest_main crc)
add_test(NAME crc16ccittfalsetest COMMAND crc16ccittfalsetest)
set_target_properties(crc16ccittfalsetest PROPERTIES FOLDER test)

# crc16cdma2000test
add_executable(crc16cdma2000test crc16cdma2000test.cpp)
target_link_libraries(crc16cdma2000test gtest gtest_main crc)
add_test(NAME crc16cdma2000test COMMAND crc16cdma2000test)
set_target_properties(crc16cdma2000test PROPERTIES FOLDER test)

# crc16dds110test
add_executable(crc16dds110test crc16dds110test.cpp)
target_link_libraries(crc16dds110test gtest gtest_main crc)
add_test(NAME crc16dds110test COMMAND crc16dds110test)
set_target_properties(crc16dds110test PROPERTIES FOLDER test)

# crc16dectrtest
add_executable(crc16dectrtest crc16dectrtest.cpp)
target_link_libraries(crc16dectrtest gtest gtest_main crc)
add_test(NAME crc16dectrtest COMMAND crc16dectrtest)
set_target_properties(crc16dectrtest PROPERTIES FOLDER test)

# crc16dectxtest
add_executable(crc16dectxtest crc16dectxtest.cpp)
target_link_libraries(crc16dectxtest gtest gtest_main crc)
add_test(NAME crc16dectxtest COMMAND crc16dectxtest)
set_target_properties(crc16dectxtest PROPERTIES FOLDER test)

# crc16dnptest
add_executable(crc16dnptest crc16dnptest.cpp)
target_link_libraries(crc16dnptest gtest gtest_main crc)
add_test(NAME crc16dnptest COMMAND crc16dnptest)
set_target_properties(crc16dnptest PROPERTIES FOLDER test)

# crc16en13757test
add_executable(crc16en13757test crc16en13757test.cpp)
target_link_libraries(crc16en13757test gtest gtest_main crc)
add_test(NAME crc16en13757test COMMAND crc16en13757test)
set_target_properties(crc16en13757test PROPERTIES FOLDER test)

# crc16genibustest
add_executable(crc16genibustest crc16genibustest.cpp)
target_link_libraries(crc16genibustest gtest gtest_main crc)
add_test(NAME crc16genibustest COMMAND crc16genibustest)
set_target_properties(crc16genibustest PROPERTIES FOLDER test)

# crc16kermittest
add_executable(crc16kermittest crc16kermittest.cpp)
target_link_libraries(crc16kermittest gtest gtest_main crc)
add_test(NAME crc16kermittest COMMAND crc16kermittest)
set_target_properties(crc16kermittest PROPERTIES FOLDER test)

# crc16maximtest
add_executable(crc16maximtest crc16maximtest.cpp)
target_link_libraries(crc16maximtest gtest gtest_main crc)
add_test(NAME crc16maximtest COMMAND crc16maximtest)
set_target_properties(crc16maximtest PROPERTIES FOLDER test)

# crc16mcrf4xxtest
add_executable(crc16mcrf4xxtest crc16mcrf4xxtest.cpp)
target_link_libraries(crc16mcrf4xxtest gtest gtest_main crc)
add_test(NAME crc16mcrf4xxtest COMMAND crc16mcrf4xxtest)
set_target_properties(crc16mcrf4xxtest PROPERTIES FOLDER test)

# crc16modbustest
add_executable(crc16modbustest crc16modbustest.cpp)
target_link_libraries(crc16modbustest gtest gtest_main crc)
add_test(NAME crc16modbustest COMMAND crc16modbustest)
set_target_properties(crc16modbustest PROPERTIES FOLDER test)

# crc16riellotest
add_executable(crc16riellotest crc16riellotest.cpp)
target_link_libraries(crc16riellotest gtest gtest_main crc)
add_test(NAME crc16riellotest COMMAND crc16riellotest)
set_target_properties(crc16riellotest PROPERTIES FOLDER test)

# crc16t10diftest
add_executable(crc16t10diftest crc16t10diftest.cpp)
target_link_libraries(crc16t10diftest gtest gtest_main crc)
add_test(NAME crc16t10diftest COMMAND crc16t10diftest)
set_target_properties(crc16t10diftest PROPERTIES FOLDER test)

# crc16teledisktest
add_executable(crc16teledisktest crc16teledisktest.cpp)
target_link_libraries(crc16teledisktest gtest gtest_main crc)
add_test(NAME crc16teledisktest COMMAND crc16teledisktest)
set_target_properties(crc16teledisktest PROPERTIES FOLDER test)

# crc16tms37157test
add_executable(crc16tms37157test crc16tms37157test.cpp)
target_link_libraries(crc16tms37157test gtest gtest_main crc)
add_test(NAME crc16tms37157test COMMAND crc16tms37157test)
set_target_properties(crc16tms37157test PROPERTIES FOLDER test)

# crc16usbtest
add_executable(crc16usbtest crc16usbtest.cpp)
target_link_libraries(crc16usbtest gtest gtest_main crc)
add_test(NAME crc16usbtest COMMAND crc16usbtest)
set_target_properties(crc16usbtest PROPERTIES FOLDER test)

# crc16x25test
add_executable(crc16x25test crc16x25test.cpp)
target_link_libraries(crc16x25test gtest gtest_main crc)
add_test(NAME crc16x25test COMMAND crc16x25test)
set_target_properties(crc16x25test PROPERTIES FOLDER test)

# crc16xmodemtest
add_executable(crc16xmodemtest crc16xmodemtest.cpp)
target_link_libraries(crc16xmodemtest gtest gtest_main crc)
add_test(NAME crc16xmodemtest COMMAND crc16xmodemtest)
set_target_properties(crc16xmodemtest PROPERTIES FOLDER test)

# crc16atest
add_executable(crc16atest crc16atest.cpp)
target_link_libraries(crc16atest gtest gtest_main crc)
add_test(NAME crc16atest COMMAND crc16atest)
set_target_properties(crc16atest PROPERTIES FOLDER test)

# crc32test
add_executable(crc32test crc32test.cpp)
target_link_libraries(crc32test gtest gtest_main crc)
add_test(NAME crc32test COMMAND crc32test)
set_target_properties(crc32test PROPERTIES FOLDER test)

# crc32bzip2test
add_executable(crc32bzip2test crc32bzip2test.cpp)
target_link_libraries(crc32bzip2test gtest gtest_main crc)
add_test(NAME crc32bzip2test COMMAND crc32bzip2test)
set_target_properties(crc32bzip2test PROPERTIES FOLDER test)

# crc32jamcrctest
add_executable(crc32jamcrctest crc32jamcrctest.cpp)
target_link_libraries(crc32jamcrctest gtest gtest_main crc)
add_test(NAME crc32jamcrctest COMMAND crc32jamcrctest)
set_target_properties(crc32jamcrctest PROPERTIES FOLDER test)

# crc32mpeg2test
add_executable(crc32mpeg2test crc32mpeg2test.cpp)
target_link_libraries(crc32mpeg2test gtest gtest_main crc)
add_test(NAME crc32mpeg2test COMMAND crc32mpeg2test)
set_target_properties(crc32mpeg2test PROPERTIES FOLDER test)

# crc32posixtest
add_executable(crc32posixtest crc32posixtest.cpp)
target_link_libraries(crc32posixtest gtest gtest_main crc)
add_test(NAME crc32posixtest COMMAND crc32posixtest)
set_target_properties(crc32posixtest PROPERTIES FOLDER test)

# crc32satatest
add_executable(crc32satatest crc32satatest.cpp)
target_link_libraries(crc32satatest gtest gtest_main crc)
add_test(NAME crc32satatest COMMAND crc32satatest)
set_target_properties(crc32satatest PROPERTIES FOLDER test)

# crc32xfertest
add_executable(crc32xfertest crc32xfertest.cpp)
target_link_libraries(crc32xfertest gtest gtest_main crc)
add_test(NAME crc32xfertest COMMAND crc32xfertest)
set_target_properties(crc32xfertest PROPERTIES FOLDER test)

# crc32ctest
add_executable(crc32ctest crc32ctest.cpp)
target_link_libraries(crc32ctest gtest gtest_main crc)
add_test(NAME crc32ctest COMMAND crc32ctest)
set_target_properties(crc32ctest PROPERTIES FOLDER test)

# crc32dtest
add_executable(crc32dtest crc32dtest.cpp)
target_link_libraries(crc32dtest gtest gtest_main crc)
add_test(NAME crc32dtest COMMAND crc32dtest)
set_target_properties(crc32dtest PROPERTIES FOLDER test)

# crc32qtest
add_executable(crc32qtest crc32qtest.cpp)
target_link_libraries(crc32qtest gtest gtest_main crc)
add_test(NAME crc32qtest COMMAND crc32qtest)
set_target_properties(crc32qtest PROPERTIES FOLDER test)
