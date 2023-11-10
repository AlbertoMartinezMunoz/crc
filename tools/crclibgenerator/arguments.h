//
// Created by alberto on 31/10/23.
//

#ifndef CRC_ARGUMENTS_H
#define CRC_ARGUMENTS_H


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


#endif //CRC_ARGUMENTS_H
