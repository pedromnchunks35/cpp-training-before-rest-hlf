#include <foo.hpp>
#include <string>
int foo::fooInt(const std::string &str)
{
    return str.size();
}
void foo::fooStr(std::string &str)
{
    str = "lol";
}
void foo::fooThrow()
{
}
void foo::callbackMethod(std::function<void(void)> &callback)
{
    callback();
}