#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <cstdint>
#include <string>
#include <map>

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

uint32_t crcTable[256];
void crcInit(CrcType_t crcType, uint32_t polynomial);

int
main (int argc, char **argv)
{
    (void)argc;(void)argv;
    struct arguments arguments;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("Arguments: p = %u, crc = % d\r\n", arguments.polynomial, arguments.crcType);

    crcInit(arguments.crcType, arguments.polynomial);

    for(int i = 0; i < 256; i++)
    {
        printf("0x%04X, ", crcTable[i]);
        if((i + 1 )%8 == 0)
            printf("\r\n");
    }
}




/*********************************************************************
 *
 * Function:    crcInit()
 *
 * Description: Populate the partial CRC lookup table.
 *
 * Notes:		This function must be rerun any time the CRC standard
 *				is changed.  If desired, it can be run "offline" and
 *				the table results stored in an embedded system's ROM.
 *
 * Returns:		None defined.
 *
 *********************************************************************/
void crcInit(CrcType_t crcType, uint32_t polynomial)
{
    (void)crcType;
    uint16_t remainder;
    int dividend;
    unsigned char bit;
    int8_t WIDTH = 16;
    uint16_t TOPBIT = (1 << (WIDTH - 1));

    for (dividend = 0; dividend < 256; ++dividend)
    {
        remainder = dividend << (WIDTH - 8);
        for (bit = 8; bit > 0; --bit)
        {
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ polynomial;
            } else
            {
                remainder = (remainder << 1);
            }
        }

        /*
         * Store the result into the table.
         */
        crcTable[dividend] = remainder;
    }

}   /* crcInit() */