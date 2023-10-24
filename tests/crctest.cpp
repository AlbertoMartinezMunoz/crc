#include <gtest/gtest.h>

class NamedPipeTest : public ::testing::Test
{
public:
    virtual void SetUp()
    {}

    virtual void TearDown()
    {}
};

TEST_F(NamedPipeTest, createfifo)
{
    EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}