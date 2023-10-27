#ifndef CRC_LOOKUPTABLE_H
#define CRC_LOOKUPTABLE_H

#include <cstdint>
#include <stdio.h>

class ILookupTable
{
public:
    /**
     * This function must be rerun any time the lookup table for a new CRC
     * standard should be computed
     */
    virtual void crcInit() = 0;

    /**
     * This function will print the lookup table in the terminal
     */
    virtual void printTable() = 0;
};

template<typename T>
class LookupTable : public ILookupTable
{
public:
    LookupTable(T polynomial) : ILookupTable()
    {
        m_polynomial = polynomial;
    }

    void crcInit() override
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
                    remainder = (remainder << 1) ^ m_polynomial;
                else
                    remainder = (remainder << 1);
            }
            m_crcTable[dividend] = remainder;
        }
    }

    void printTable() override
    {
        for(int i = 0; i < 256; i++)
        {
            printf("0x%04X, ", m_crcTable[i]);
            if((i + 1 )%8 == 0)
                printf("\r\n");
        }
    }

private:
    T m_polynomial;
    T m_crcTable[256];
};

#endif //CRC_LOOKUPTABLE_H
