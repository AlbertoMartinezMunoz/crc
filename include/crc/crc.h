#ifndef CRC_CRC_H
#define CRC_CRC_H

#include <cstdint>

template<typename T>
class Crc
{
public:
    Crc(const T *lookupTable, const T finalXorRemainder) :
        m_lookupTable(lookupTable),
        m_finalXorRemainder(finalXorRemainder)
    {}

    virtual uint8_t reflectData(uint8_t data) = 0;

    virtual T reflectRemainder(T data) = 0;

    T computeCrc(const uint8_t *buffer, const std::size_t size)
    {
        uint16_t remainder = 0xFFFF;
        uint8_t data;
        std::size_t byte;

        for (byte = 0; byte < size; ++byte) {
            data = reflectData(buffer[byte]) ^ (remainder >> (m_typeBits - 8));
            remainder = m_lookupTable[data] ^ (remainder << 8);
        }

        remainder = reflectRemainder(remainder) ^ m_finalXorRemainder;
        return remainder;
    }

    T reflect(T data, uint8_t nBits) {
        T reflection = 0x00000000;
        uint8_t bit;

        for (bit = 0; bit < nBits; ++bit) {
            if (data & 0x01) {
                reflection |= (1 << ((nBits - 1) - bit));
            }
            data = (data >> 1);
        }

        return (reflection);
    }

    const T *m_lookupTable;

    const std::size_t m_typeBits = (8 * sizeof(T));

    const T m_finalXorRemainder;
};

#endif //CRC_CRC_H
