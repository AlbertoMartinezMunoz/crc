#ifndef CRC_LOOKUPTABLE_H
#define CRC_LOOKUPTABLE_H

#include <cstdint>
#include <stdio.h>
#include <string>

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
    virtual void writeTable(std::string &table) = 0;
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

    void writeTable(std::string &table) override
    {
        char formatStr[16], tableValue[16];
        std::string tableValueStr;
        table = "            ";

        sprintf(formatStr, "0x%%0%luX", sizeof(T) * 2);

        for(int i = 0; i < 256; i++)
        {
            sprintf(tableValue, formatStr, m_crcTable[i]);
            tableValueStr = tableValue;
            if((i + 1 )%8 == 0)
            {
                if(i == 255)
                    table += tableValueStr;
                else
                    table += tableValueStr + ",\r\n            ";
            }
            else
                table += tableValueStr + ", ";
        }
    }

private:
    T m_polynomial;
    T m_crcTable[256];
};

#endif //CRC_LOOKUPTABLE_H
