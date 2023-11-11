#include <crc/crc16tms37157.h>

#include <memory>

#include <gtest/gtest.h>

class Crc16Tms37157Test : public ::testing::Test
{
public:
    virtual void SetUp()
    {
        m_crc = std::make_unique<Crc16Tms37157>();
    }

    virtual void TearDown()
    {}

protected:

    std::unique_ptr<Crc<uint16_t>> m_crc;

    const uint8_t m_checkBuffer01[9] = {0x31, 0x32, 0x33, 0x34, 0x35,
                                        0x36, 0x37, 0x38, 0x39};
    const uint8_t m_checkBuffer02[9] = {0x41, 0x42, 0x43, 0x44, 0x45,
                                        0x46, 0x47, 0x48, 0x49};
    const uint16_t m_checkBuffer01Crc = 9905;
    const uint16_t m_checkBuffer02Crc = 0x51;
};

TEST_F(Crc16Tms37157Test, crc01)
{
    EXPECT_EQ(m_crc->computeCrc(m_checkBuffer01, sizeof(m_checkBuffer01)), m_checkBuffer01Crc);
}

TEST_F(Crc16Tms37157Test, DISABLED_crc02)
{
    EXPECT_EQ(m_crc->computeCrc(m_checkBuffer02, sizeof(m_checkBuffer02)), m_checkBuffer02Crc);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}