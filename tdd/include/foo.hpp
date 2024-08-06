#ifndef FOO_HPP
#define FOO_HPP
#include "foo_if.hpp"
#include <functional>
class foo : public fooIf
{
public:
    int fooInt(const std::string &str);
    void fooStr(std::string &str);
    void foo::fooThrow();
    void foo::callbackMethod(std::function<void(void)> &callback);
};
#endif