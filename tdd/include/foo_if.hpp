#ifndef FOO_IF_HPP
#define FOO_IF_HPP
#include <string>
#include <functional>
//? IF WE WANT OUR fooStr to be overrided we must put =0;
class fooIf
{
public:
    virtual int fooInt(const std::string &str) = 0;
    virtual void fooStr(std::string &str) = 0;
    virtual void fooThrow() = 0;
    virtual void callbackMethod(std::function<void(void)> &callback) = 0;
};
#endif