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
        int8_t crcWidth = sizeof(T) * 8;
        T crcTopBit = (1 << (crcWidth - 1));

        for (dividend = 0; dividend < 256; ++dividend)
        {
            remainder = dividend << (crcWidth - 8);
            for (bit = 8; bit > 0; --bit)
            {
                if (remainder & crcTopBit)
                    remainder = (remainder << 1) ^ polynomial;
                else
                    remainder = (remainder << 1);
            }
            m_crcTable[dividend] = remainder;
        }
    }

    void printTable()
    {
        for(int i = 0; i < 256; i++)
        {
            printf("0x%04X, ", m_crcTable[i]);
            if((i + 1 )%8 == 0)
                printf("\r\n");
        }
    }

private:
    T m_crcTable[256];
};

#endif //CRC_LOOKUPTABLE_H
