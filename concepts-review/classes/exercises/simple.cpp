#include <iostream>
class StaticPoly
{
public:
    StaticPoly() {};
    void print(int i)
    {
        std::cout << i << "\n";
    }
    void print(double i)
    {
        std::cout << i << "\n";
    }
};
class DynamicPoly
{
public:
    DynamicPoly() {}
    virtual void print()
    {
        std::cout << "Parent" << "\n";
    }
    virtual void pureMethod() = 0;
};
class DynamicPolyChild : DynamicPoly
{
public:
    DynamicPolyChild() {}
    void print() override
    {
        std::cout << "Hello from child" << "\n";
    }
    void pureMethod() override
    {
        std::cout << "After this you are allowed" << "\n";
    }
};
int main()
{
    StaticPoly s;
    s.print(1);
    s.print(2.2);
    DynamicPolyChild dpc;
    dpc.print();
    dpc.pureMethod();
}