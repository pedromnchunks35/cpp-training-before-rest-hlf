#include "dummy.hpp"
int dummy::dummyInt(const std::string &str)
{
    return mFoo.fooInt(str);
}
void dummy::dummyChangeStr(std::string &str)
{
    mFoo.fooStr(str);
}
void dummy::dummyfooThrow()
{
    mFoo.fooThrow();
}
void dummy::dummycallbackMethod(std::function<void(void)> &callback)
{
    mFoo.callbackMethod(callback);
}