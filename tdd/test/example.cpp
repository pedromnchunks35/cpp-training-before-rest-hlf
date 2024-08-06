#include <iostream>
#include <gtest/gtest.h>
//? A CLASS JUST FOR THE PURPOSES OF TESTING RANDOM THINGS OUT
class example
{
public:
    int foo()
    {
        return 1;
    }
};
//? CREATING A CLASS THAT ACTUALLY INITS SOMETHING THE NAME OF THE CLASS CAN BE ANYTHING
//? WE CAN ALSO USE THIS TO SET UP OR TEAR DOWN SOMETHING
//? THIS IS ALMOST HOW WE CAN SETUP A FOR EACH
class testFixtures : public testing::Test
{
public:
    testFixtures()
    {
        std::cout << "INIT TEST" << "\n";
        ex = new example();
    }
    ~testFixtures()
    {
        std::cout << "THE CLEAN" << "\n";
    }
    void SetUp()
    {
        std::cout << "SETUP FOR THE TEST" << "\n";
    }
    void TearDown()
    {
        std::cout << "TEAR DOWN FOR THE TEST" << "\n";
    }

    example *ex;
};
TEST_F(testFixtures, test3)
{
    ASSERT_EQ(1, ex->foo());
}
//? NORMAL TESTING
TEST(exampleTest, test1)
{
    ASSERT_EQ(1, 1);
}
TEST(exampleTest, test2)
{
    ASSERT_NE(1, 0);
}
//! THIS IS NOT NEEDED IF WE ADD SOMETHING IN THE CMAKE FILE
/* int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} */