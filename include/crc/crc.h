#ifndef CRC_CRC_H
#define CRC_CRC_H

#include <cstdint>

/**
 * This class will implement a CRC calculator of width defined by T
 * @tparam T Type of the CRC (uint8_t for CRC8, uint16_t for CRC16 and uint32_t
 *           for CRC32)
 */
template<typename T>
class Crc
{
public:
    /**
     * This function will compute the CRC based on the configuration of the derived class
     * @param buffer Data buffer from which the CRC will be generated
     * @param size   Number of bytes of the data buffer
     * @return       CRC of the data buffer
     */
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

protected:
    /**
     * CRC constructor. Is protected so it can be only called from derived
     * classes which implement a concrete CRC standard
     * @param lookupTable        Concrete standard look up table
     * @param finalXorRemainder  Concrete standard value to xor with the CRC
     *                           before returning it
     */
    Crc(const T *lookupTable, const T finalXorRemainder) :
        m_lookupTable(lookupTable),
        m_finalXorRemainder(finalXorRemainder)
    {}

    /**
     * Reorder the bits of a binary sequence, by reflecting them about the
     * middle position.
     * @param data  Data to be reordered
     * @param nBits Number of bits to be reordered
     * @return      The reflection of the original data.
     */
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

private:

    /**
     * This function will reflect the tmp data when computing the CRC if needed
     * by the concrete standard
     * @param data Byte to be reflected
     * @return     Reflected data if needed by the concrete CRC standard
     */
    virtual uint8_t reflectData(uint8_t data) = 0;

    /**
     * This function will reflect the final reminder when computing the CRC if
     * needed by the concrete standard
     * @param data Remainder to be reflected
     * @return     Reflected data if needed by the concrete CRC standard
     */
    virtual T reflectRemainder(T remainder) = 0;

protected:
    const std::size_t m_typeBits = (8 * sizeof(T));

private:
    const T *m_lookupTable;

    const T m_finalXorRemainder;
};

#endif //CRC_CRC_H
