#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <string>
#include "foo_if.hpp"
#include <functional>
class dummy
{
public:
    dummy(fooIf &newMFoo) : mFoo(newMFoo) {}
    int dummyInt(const std::string &str);
    void dummyChangeStr(std::string &str);
    void dummyfooThrow();
    void dummycallbackMethod(std::function<void(void)> &callback);
    fooIf &mFoo;
};
#endif