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
        {"polynomial", 'p', "hex int", 0, "Polynomial used for calculating the CRC", 0},
        {0,            0,   0, 0, 0,                                                               0}
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
    struct arguments arguments;
    ILookupTable *lookupTable;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    switch (arguments.crcType)
    {
        case CRC8:
            lookupTable = new LookupTable<uint8_t>(arguments.polynomial);
            break;
        case CRC16:
            lookupTable = new LookupTable<uint16_t>(arguments.polynomial);
            break;
        case CRC32:
            lookupTable = new LookupTable<uint32_t>(arguments.polynomial);
            break;
    }

    lookupTable->crcInit();
    lookupTable->printTable();
}




