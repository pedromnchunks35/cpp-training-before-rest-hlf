#include "foo_if.hpp"
#include <gmock/gmock.h>
#include <functional>
//? We dont have to implement a interface but its always a good practise to do so
class mockFoo : public fooIf
{
public:
    //? THIS IS HOW WE WILL MOCK THE FOO
    //? @param int, the return type
    //? @param fooInt, name of the function
    //? @param (const std::string&str), the signature of the method
    //? @param (override), if this overrides a function
    MOCK_METHOD(int, fooInt, (const std::string &str), (override));
    MOCK_METHOD(void, fooStr, (std::string & str), (override));
    MOCK_METHOD(void, fooThrow, (), (override));
    MOCK_METHOD(void, callbackMethod, (std::function<void(void)> & callback), (override));
};