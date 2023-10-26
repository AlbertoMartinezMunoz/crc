#ifndef CRC_LOOKUPTABLE_H
#define CRC_LOOKUPTABLE_H

#include <cstdint>
#include <stdio.h>

template<typename T>
class LookupTable
{
public:
    void crcInit(uint32_t polynomial)
    {
        T remainder;
        int dividend;
        unsigned char bit;
        int8_t WIDTH = 16;
        T TOPBIT = (1 << (WIDTH - 1));

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

    void printTable()
    {
        for(int i = 0; i < 256; i++)
        {
            printf("0x%04X, ", crcTable[i]);
            if((i + 1 )%8 == 0)
                printf("\r\n");
        }
    }

private:
    T crcTable[256];
};

#endif //CRC_LOOKUPTABLE_H
