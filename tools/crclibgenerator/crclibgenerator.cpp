#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <cstdint>
#include <string>
#include <map>
#include <fstream>

#include "lookuptable.h"

static std::map<int, std::string> s_mapCRCTypes = {{8,"uint8_t"},{16,"uint16_t"},{32,"uint32_t"}};

const char *argp_program_version = "lookup-table-generator v1.0.0";
const char *argp_program_bug_address = "<traquinedes@yahoo.es>";

static char doc[] = "Tool for generating the library for a CRC algorithm";

struct arguments
{
    char *libName;
    uint32_t polynomial;
    int8_t width;
    uint32_t initial;
    uint32_t check;
    bool shouldInvertData;
    bool shouldInvertOutput;
    uint32_t xorOutput;
    char numberOfMandatoryOptions = 0;
};

static char args_doc[] = "[library-name]";

static struct argp_option options[] =
{
        {"width",         'w', "int8",    0, "Should be 8, 16 or 32",                     0},
        {"polynomial",    'p', "hex int", 0, "Polynomial used for calculating the CRC",   0},
        {"initial",       'i', "hex int", 0, "Initial value for start computing the CRC", 0},
        {"check",         'c', "hex int", 0, "Value for check in utest",                  0},
        {"invert-data",   'd', 0,         0, "If present, should reflect the input data", 0},
        {"invert-output", 'o', 0,         0, "If present, should reflect the output crc", 0},
        {"xor-output",    'x', "hex int", 0, "XOR this value with CRC.",                  0},
        {0,               0,   0,         0, 0,                                           0}
};

/**
 * Parse a single option.
 * @param key
 * @param arg   Holds the argument value
 * @param state
 * @return
 */
static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = (struct arguments *)(state->input);

    switch (key)
    {
        case 'w':
            arguments->width = std::stoul(arg, nullptr, 10);
            arguments->numberOfMandatoryOptions++;
            break;
        case 'p':
            arguments->polynomial = std::stoul(arg, nullptr, 16);
            arguments->numberOfMandatoryOptions++;
            break;
        case 'c':
            arguments->check = std::stoul(arg, nullptr, 16);
            arguments->numberOfMandatoryOptions++;
            break;
        case 'i':
            arguments->initial = std::stoul(arg, nullptr, 16);
            arguments->numberOfMandatoryOptions++;
            break;
        case 'd':
            arguments->shouldInvertData = true;
            break;
        case 'o':
            arguments->shouldInvertOutput = true;
            break;
        case 'x':
            arguments->xorOutput = std::stoul(arg, nullptr, 16);
            arguments->numberOfMandatoryOptions++;
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num >= 1)
            {
                printf("Too many arguments.\r\n");
                argp_usage(state);
                return ARGP_ERR_UNKNOWN;
            }
            arguments->libName = arg;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 1)
            {
                printf("Not enough arguments.\r\n");
                argp_usage(state);
            }
            else if(arguments->numberOfMandatoryOptions < 5)
            {
                printf("Missing mandatory options.\r\n");
                argp_usage(state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc,0,0,0};

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

    arguments.shouldInvertOutput = false;
    arguments.shouldInvertData = false;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    printf("Arguments: poly = 0x%X, width = %u, ini = 0x%X, id = %d, io = %d, xOut = 0x%X, check = 0x%X lib = '%s'\r\n", arguments.polynomial,
           arguments.width, arguments.initial, arguments.shouldInvertData, arguments.shouldInvertOutput,arguments.xorOutput,arguments.check ,arguments.libName);

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
    if(arguments.width == 8)
        lookupTable = new LookupTable<uint16_t>(arguments.polynomial);
    else
        lookupTable = new LookupTable<uint32_t>(arguments.polynomial);

    lookupTable->crcInit();
    lookupTable->writeTable(table);



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
              "    static const " + classType + " m_finalXorValue = " + std::to_string(arguments.xorOutput) + ";\r\n" +
              "    static const " + classType + " m_initialRemainder = " + std::to_string(arguments.initial) + ";\r\n" +
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
              "    const " + classType + " m_checkBuffer01Crc = " + std::to_string(arguments.check) + ";\r\n" +
              "    const " + classType + " m_checkBuffer02Crc = 0x51AE;\r\n" +
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




