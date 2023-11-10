#ifndef CRC_LOOKUPTABLE_H
#define CRC_LOOKUPTABLE_H

#include <cstdint>
#include <stdio.h>
#include <string>

class ILookupTable
{
public:
    /**
     * This function will print the lookup table in a string
     * @param table string which will hold the lookup table
     */
    virtual void createTable(std::string &table) = 0;
};

template<typename T>
class LookupTable : public ILookupTable
{
public:
    LookupTable(T polynomial) : ILookupTable()
    {
        m_polynomial = polynomial;
    }

    void createTable(std::string &table) override
    {
        table = "            ";
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
            addValueToTable(table, remainder, dividend);
        }
    }

private:
    T m_polynomial;
    T m_crcTable[256];

    void addValueToTable(std::string &table, T value, int index)
    {
        char formatStr[16], tableValue[16];

        sprintf(formatStr, "0x%%0%luX", sizeof(T) * 2);
        sprintf(tableValue, formatStr, value);
        table += std::string(tableValue);
        if ((index + 1) % 8 == 0)
        {
            if (index != 255)
                table += ",\r\n            ";
        } else
            table += ", ";
    }
};

#endif //CRC_LOOKUPTABLE_H
