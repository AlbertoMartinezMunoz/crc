#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <cstdint>
#include <string>
#include <map>

#include "lookuptable.h"

typedef enum
{
    CRC8,CRC16,CRC32
} CrcType_t;

static std::map<std::string, CrcType_t> s_mapCRCValues = {{"CRC8",CRC8},{"CRC16",CRC16},{"CRC32",CRC32}};

const char *argp_program_version = "lookup-table-generator v1.0.0";
const char *argp_program_bug_address = "<traquinedes@yahoo.es>";

static char doc[] = "Tool for generating lookup tables for a CRC algorithm";

struct arguments
{
    uint32_t polynomial;
    CrcType_t crcType;
};

static char args_doc[] = "[CRC8|CRC16|CRC32]";

static struct argp_option options[] =
{
        {"polinomial", 'p', "polinomial", 0, "Hexadeciaml integer. Polinomial used for calculating the CRC.", 0},
        {0,            0,   0, 0, 0,                                                               0}
};

/**
 * Parse a single option.
 * @param key
 * @param arg
 * @param state
 * @return
 */
static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = (struct arguments *)(state->input);

    switch (key)
    {
        case 'p':
            arguments->polynomial = std::stoul(arg, nullptr, 16);
            break;
        case ARGP_KEY_ARG:
            if (state->arg_num >= 1)
            {
                printf("Too many arguments.\r\n");
                argp_usage(state);
                return ARGP_ERR_UNKNOWN;
            }
            arguments->crcType = s_mapCRCValues[arg];
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 1)
            {
                printf("Not enough arguments.\r\n");
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
    (void)argc;(void)argv;
    struct arguments arguments;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("Arguments: p = %u, crc = % d\r\n", arguments.polynomial, arguments.crcType);

    switch (arguments.crcType)
    {
        case CRC8:
            LookupTable<uint8_t> lookuptable8;
            lookuptable8.crcInit(arguments.polynomial);
            lookuptable8.printTable();
            break;
        case CRC16:
            LookupTable<uint16_t> lookuptable16;
            lookuptable16.crcInit(arguments.polynomial);
            lookuptable16.printTable();
            break;
        case CRC32:
            LookupTable<uint32_t> lookuptable32;
            lookuptable32.crcInit(arguments.polynomial);
            lookuptable32.printTable();
            break;
    }
}




