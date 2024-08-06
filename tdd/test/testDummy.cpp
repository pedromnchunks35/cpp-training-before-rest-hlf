#include <iostream>
#include <gtest/gtest.h>
#include <dummy.hpp>
#include <mock_foo.hpp>
class testFixtureDummy : public testing::Test
{
public:
    testFixtureDummy()
    {
        mTestDummy = std::make_unique<dummy>(mfoo);
    }
    ~testFixtureDummy() {}
    void SetUp() {}
    void TearDown() {}
    mockFoo mfoo;
    std::unique_ptr<dummy> mTestDummy;
};
TEST_F(testFixtureDummy, dummyInt)
{
    std::string str{"lul"};
    std::string otherval{"lol"};
    //? THIS IS WHAT WE WILL MAKE MOCK RETURN
    //? SHOULD ALWAYS STAY BEFORE THE FUNCTION
    EXPECT_CALL(mfoo, fooInt(str)).Times(1).WillOnce(testing::Return(str.size()));
    int result = mTestDummy->dummyInt(str);
    ASSERT_EQ(result, str.size());
}
TEST_F(testFixtureDummy, dummyStr)
{
    std::string str{"lul"};
    std::string otherval{"lol"};
    //? AN EXPECT TO VOID THAT CHANGES A REFERENCE VALUE
    //? We can put testing::_ in the argument field of the function if we meant like whatever argument its received in the arg
    EXPECT_CALL(mfoo, fooStr(str)).WillOnce(testing::SetArgReferee<0>(otherval));
    mTestDummy->dummyChangeStr(str);
    ASSERT_EQ(str, otherval);
}
ACTION(throwError)
{
    throw std::runtime_error("ERROR TEST");
}
void throwFunction()
{
    std::cout << "ERROR!\n";
    throw std::runtime_error("ERROR_TEST");
}
TEST_F(testFixtureDummy, dummyThrow)
{
    EXPECT_CALL(mfoo, fooThrow()).WillOnce(throwError());
    ASSERT_THROW(mTestDummy->dummyfooThrow(), std::runtime_error);
    EXPECT_CALL(mfoo, fooThrow()).WillOnce(testing::Invoke(throwFunction));
    ASSERT_THROW(mTestDummy->dummyfooThrow(), std::runtime_error);
}

TEST_F(testFixtureDummy, TestCallBack)
{
    // Create a mock function object to use as a callback
    testing::MockFunction<void(void)> testFunc;

    // Set expectation that testFunc.Call() will be called
    EXPECT_CALL(testFunc, Call()).Times(1);

    // Set up the mock object mfoo to expect callbackMethod to be called
    // with a std::function<void()> that will invoke testFunc.Call()
    EXPECT_CALL(mfoo, callbackMethod(testing::_))
        .Times(1)
        .WillOnce(testing::Invoke([&](std::function<void()> &cb)
                                  {
                                      // Invoke the callback passed to callbackMethod
                                      cb(); // This should call testFunc.Call()
                                  }));

    // Convert MockFunction to std::function
    std::function<void()> cb = testFunc.AsStdFunction();

    // Call the method under test with the converted std::function
    mTestDummy->dummycallbackMethod(cb);
}
