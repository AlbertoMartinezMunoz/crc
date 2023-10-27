#ifndef CRC_CRC32_H
#define CRC_CRC32_H

#include <crc/crc.h>

class Crc32 : public Crc<uint32_t>
{
public:
    /**
     * Will construct a CRC class of type CRC16/USB
     */
    Crc32() : Crc<uint32_t>(m_lookupTable, m_initialRemainder, m_finalXorValue) {}

private:
    uint8_t reflectData(uint8_t data) override
    {
        return Crc<uint32_t>::reflect(data, 8);
    }

    uint32_t reflectRemainder(uint32_t remainder) override
    {
        return Crc<uint32_t>::reflect(remainder, Crc::m_typeBits);
    }

private:
    uint32_t m_lookupTable[256] = {
            0x0000, 0x1DB7, 0x3B6E, 0x26D9, 0x76DC, 0x6B6B, 0x4DB2, 0x5005,
            0xEDB8, 0xF00F, 0xD6D6, 0xCB61, 0x9B64, 0x86D3, 0xA00A, 0xBDBD,
            0xC6C7, 0xDB70, 0xFDA9, 0xE01E, 0xB01B, 0xADAC, 0x8B75, 0x96C2,
            0x2B7F, 0x36C8, 0x1011, 0x0DA6, 0x5DA3, 0x4014, 0x66CD, 0x7B7A,
            0x9039, 0x8D8E, 0xAB57, 0xB6E0, 0xE6E5, 0xFB52, 0xDD8B, 0xC03C,
            0x7D81, 0x6036, 0x46EF, 0x5B58, 0x0B5D, 0x16EA, 0x3033, 0x2D84,
            0x56FE, 0x4B49, 0x6D90, 0x7027, 0x2022, 0x3D95, 0x1B4C, 0x06FB,
            0xBB46, 0xA6F1, 0x8028, 0x9D9F, 0xCD9A, 0xD02D, 0xF6F4, 0xEB43,
            0x3DC5, 0x2072, 0x06AB, 0x1B1C, 0x4B19, 0x56AE, 0x7077, 0x6DC0,
            0xD07D, 0xCDCA, 0xEB13, 0xF6A4, 0xA6A1, 0xBB16, 0x9DCF, 0x8078,
            0xFB02, 0xE6B5, 0xC06C, 0xDDDB, 0x8DDE, 0x9069, 0xB6B0, 0xAB07,
            0x16BA, 0x0B0D, 0x2DD4, 0x3063, 0x6066, 0x7DD1, 0x5B08, 0x46BF,
            0xADFC, 0xB04B, 0x9692, 0x8B25, 0xDB20, 0xC697, 0xE04E, 0xFDF9,
            0x4044, 0x5DF3, 0x7B2A, 0x669D, 0x3698, 0x2B2F, 0x0DF6, 0x1041,
            0x6B3B, 0x768C, 0x5055, 0x4DE2, 0x1DE7, 0x0050, 0x2689, 0x3B3E,
            0x8683, 0x9B34, 0xBDED, 0xA05A, 0xF05F, 0xEDE8, 0xCB31, 0xD686,
            0x7B8A, 0x663D, 0x40E4, 0x5D53, 0x0D56, 0x10E1, 0x3638, 0x2B8F,
            0x9632, 0x8B85, 0xAD5C, 0xB0EB, 0xE0EE, 0xFD59, 0xDB80, 0xC637,
            0xBD4D, 0xA0FA, 0x8623, 0x9B94, 0xCB91, 0xD626, 0xF0FF, 0xED48,
            0x50F5, 0x4D42, 0x6B9B, 0x762C, 0x2629, 0x3B9E, 0x1D47, 0x00F0,
            0xEBB3, 0xF604, 0xD0DD, 0xCD6A, 0x9D6F, 0x80D8, 0xA601, 0xBBB6,
            0x060B, 0x1BBC, 0x3D65, 0x20D2, 0x70D7, 0x6D60, 0x4BB9, 0x560E,
            0x2D74, 0x30C3, 0x161A, 0x0BAD, 0x5BA8, 0x461F, 0x60C6, 0x7D71,
            0xC0CC, 0xDD7B, 0xFBA2, 0xE615, 0xB610, 0xABA7, 0x8D7E, 0x90C9,
            0x464F, 0x5BF8, 0x7D21, 0x6096, 0x3093, 0x2D24, 0x0BFD, 0x164A,
            0xABF7, 0xB640, 0x9099, 0x8D2E, 0xDD2B, 0xC09C, 0xE645, 0xFBF2,
            0x8088, 0x9D3F, 0xBBE6, 0xA651, 0xF654, 0xEBE3, 0xCD3A, 0xD08D,
            0x6D30, 0x7087, 0x565E, 0x4BE9, 0x1BEC, 0x065B, 0x2082, 0x3D35,
            0xD676, 0xCBC1, 0xED18, 0xF0AF, 0xA0AA, 0xBD1D, 0x9BC4, 0x8673,
            0x3BCE, 0x2679, 0x00A0, 0x1D17, 0x4D12, 0x50A5, 0x767C, 0x6BCB,
            0x10B1, 0x0D06, 0x2BDF, 0x3668, 0x666D, 0x7BDA, 0x5D03, 0x40B4,
            0xFD09, 0xE0BE, 0xC667, 0xDBD0, 0x8BD5, 0x9662, 0xB0BB, 0xAD0C };

    static const uint32_t m_finalXorValue = 4294967295;
    static const uint32_t m_initialRemainder = 4294967295;
};


#endif //CRC_CRC32_H
