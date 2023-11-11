#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <cstdint>
#include <string>
#include <map>
#include <fstream>

#include "lookuptable.h"
#include "arguments.h"

int main (int argc, char **argv)
{
    std::string libPath;
    std::string libText;
    std::string libNameUpper;
    std::string className;
    std::string classType;
    std::string reflectData = "        return data;\r\n";
    std::string reflectRemainder = "        return remainder;\r\n";
    std::string table;
    std::string libTestPath;
    std::string libTest;
    std::string libTestCheck;
    ILookupTable *lookupTable;
    struct arguments arguments;
    char formatStr[16], xorOutputStr[16], initialStr[16], checkStr[16];

    arguments.shouldInvertOutput = false;
    arguments.shouldInvertData = false;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    libPath = arguments.libName;
    libPath+=".h";

    libNameUpper = arguments.libName;
    for (auto & c: libNameUpper) c = toupper(c);

    className = arguments.libName;
    className[0] = toupper(className[0] );
    arguments.width != 8? className[5] = toupper(className[5] ) : className[4] = toupper(className[4] );

    classType = s_mapCRCTypes[arguments.width];

    if(arguments.shouldInvertData)
        reflectData = "        return Crc<" + classType + ">::reflect(data, 8);\r\n";

    if(arguments.shouldInvertOutput)
        reflectRemainder = "        return Crc<" + classType + ">::reflect(remainder, Crc::m_typeBits);\r\n";

    if(arguments.width == 8)
        lookupTable = new LookupTable<uint8_t>(arguments.polynomial);
    else if(arguments.width == 16)
        lookupTable = new LookupTable<uint16_t>(arguments.polynomial);
    else
        lookupTable = new LookupTable<uint32_t>(arguments.polynomial);

    lookupTable->createTable(table);


    sprintf(formatStr, "0x%%0%dX", arguments.width >> 2);
    sprintf(xorOutputStr, formatStr, arguments.xorOutput);
    sprintf(initialStr, formatStr, arguments.initial);
    sprintf(checkStr, formatStr, arguments.check);

    libText = "#ifndef CRC_" + libNameUpper + "_H\r\n" +
              "#define CRC_" + libNameUpper + "_H\r\n" +
              "\r\n" +
              "#include <crc/crc.h>\r\n" +
              "\r\n" +
              "class " + className + " : public Crc<" + classType + ">\r\n" +
              "{\r\n" +
              "public:\r\n" +
              "    /**\r\n" +
              "     * Will construct a CRC class of type CRC16/USB\r\n" +
              "     */\r\n" +
              "    " + className + "() : Crc<" + classType + ">(m_lookupTable, m_initialRemainder, m_finalXorValue) {}\r\n" +
              "\r\n" +
              "private:\r\n" +
              "    uint8_t reflectData(uint8_t data) override\r\n" +
              "    {\r\n" +
              reflectData +
              "    }\r\n" +
              "\r\n" +
              "    " + classType + " reflectRemainder(" + classType + " remainder) override\r\n" +
              "    {\r\n" +
              reflectRemainder +
              "    }\r\n" +
              "\r\n" +
              "private:\r\n" +
              "    " + classType + " m_lookupTable[256] = {\r\n" +
              table + " };\r\n" +
              "\r\n" +
              "    static const " + classType + " m_finalXorValue = " + xorOutputStr + ";\r\n" +
              "    static const " + classType + " m_initialRemainder = " + initialStr + ";\r\n" +
              "};\r\n\r\n\r\n" +
              "#endif //CRC_" + libNameUpper + "_H\r\n";

    std::ofstream crclib(libPath, std::fstream::out | std::fstream::trunc);
    crclib << libText;
    crclib.close();

    libTestPath = arguments.libName;
    libTestPath+="test.cpp";

    libTest = "#include <crc/"+ libPath +">\r\n" +
              "\r\n" +
              "#include <memory>\r\n" +
              "\r\n" +
              "#include <gtest/gtest.h>\r\n" +
              "\r\n" +
              "class " + className + "Test : public ::testing::Test\r\n" +
              "{\r\n" +
              "public:\r\n" +
              "    virtual void SetUp()\r\n" +
              "    {\r\n" +
              "        m_crc = std::make_unique<" + className + ">();\r\n" +
              "    }\r\n" +
              "\r\n" +
              "    virtual void TearDown()\r\n" +
              "    {}\r\n" +
              "\r\n" +
              "protected:\r\n" +
              "\r\n" +
              "    std::unique_ptr<Crc<" + classType + ">> m_crc;\r\n" +
              "\r\n" +
              "    const uint8_t m_checkBuffer01[9] = {0x31, 0x32, 0x33, 0x34, 0x35,\r\n" +
              "                                        0x36, 0x37, 0x38, 0x39};\r\n" +
              "    const uint8_t m_checkBuffer02[9] = {0x41, 0x42, 0x43, 0x44, 0x45,\r\n" +
              "                                        0x46, 0x47, 0x48, 0x49};\r\n" +
              "    const " + classType + " m_checkBuffer01Crc = " + checkStr + ";\r\n" +
              "    const " + classType + " m_checkBuffer02Crc = 0x51;\r\n" +
              "};\r\n" +
              "\r\n" +
              "TEST_F(" + className + "Test, crc01)\r\n" +
              "{\r\n" +
              "    EXPECT_EQ(m_crc->computeCrc(m_checkBuffer01, sizeof(m_checkBuffer01)), m_checkBuffer01Crc);\r\n" +
              "}\r\n" +
              "\r\n" +
              "TEST_F(" + className + "Test, DISABLED_crc02)\r\n" +
              "{\r\n" +
              "    EXPECT_EQ(m_crc->computeCrc(m_checkBuffer02, sizeof(m_checkBuffer02)), m_checkBuffer02Crc);\r\n" +
              "}\r\n" +
              "\r\n" +
              "int main(int argc, char **argv)\r\n" +
              "{\r\n" +
              "    ::testing::InitGoogleTest(&argc, argv);\r\n" +
              "    return RUN_ALL_TESTS();\r\n" +
              "}";



    std::ofstream crclibtest(libTestPath, std::fstream::out | std::fstream::trunc);
    crclibtest << libTest;
    crclibtest.close();

    std::string libName = arguments.libName;

    std::string cmake = "\r\n\r\n# " + libName + "test\r\n" +
                        "add_executable(" + libName + "test " + libName + "test.cpp)\r\n" +
                        "target_link_libraries(" + libName + "test gtest gtest_main crc)\r\n" +
                        "add_test(NAME " + libName + "test COMMAND " + libName + "test)\r\n" +
                        "set_target_properties(" + libName + "test PROPERTIES FOLDER test)\r\n\r\n";
    printf("%s",cmake.c_str());
}




