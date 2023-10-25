#ifndef CRC_CRC_H
#define CRC_CRC_H

#include <cstdint>

template<typename T>
class Crc
{
public:
    T computeCrc(const uint8_t *buffer, const std::size_t size)
    {
        (void )buffer;
        (void)size;
        return 0;
    }
};

#endif //CRC_CRC_H
