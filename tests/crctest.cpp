#include <gtest/gtest.h>

class CrcTest : public ::testing::Test
{
public:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(CrcTest, true)
{
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}