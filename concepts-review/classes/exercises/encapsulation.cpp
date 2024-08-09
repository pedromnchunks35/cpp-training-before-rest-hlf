#include <iostream>
class Parent
{

public:
    int pubParent;
    Parent() {}

private:
    int privParent;

protected:
    int protParent;
};
class Child : public Parent
{
public:
    Child() {}
    int pubChild;
    void tryAccess()
    {
        std::cout << pubParent << "\n";
        std::cout << protParent << "\n";
        //? We cant access the private one (obvious)
    }

private:
    int privChild;

protected:
    int protChild;
};
class Child2 : private Parent
{
public:
    Child2() {}
    int pubChild2;
    void tryAccess()
    {
        std::cout << pubParent << "\n";
        std::cout << protParent << "\n";
        //? We cant access the private one (obvious)
    }

private:
    int privChild2;

protected:
    int protChild2;
};
class Child3 : protected Parent
{
public:
    Child3() {}
    int pubChild3;
    void tryAccess()
    {
        std::cout << pubParent << "\n";
        std::cout << protParent << "\n";
        //? We cant access the private one (obvious)
    }

private:
    int privChild3;

protected:
    int protChild3;
};
class Child4 : public Child2
{
public:
    int pubChild4;
    Child4() {}
    void tryAccess()
    {
        std::cout << pubChild4 << "\n";
        std::cout << pubChild2 << "\n";
        //! NOT ACESSIBLE BECAUSE ITS PRIVATE
        /* std::cout << pubParent << "\n"; */
    }

private:
    int privChild4;

protected:
    int protChild4;
};
class Child5 : public Child3
{
public:
    int pubChild5;
    Child5() {}

private:
    int privChild5;

protected:
    int protChild5;
};
int main()
{ //? CAN ONLY ACCESS PUBLIC
    Parent p;
    p.pubParent;
    //? CAN ONLY ACCESS PUBLIC BUT FROM PARENT AS WELL
    Child child;
    child.pubChild;
    child.pubParent;
    //? CANT ACCESS THE PARENT BECAUSE PARENT IS PRIVATE
    Child2 child2;
    child2.pubChild2;
    //? CANT ACCESS THE PARENT BECAUSE ITS PROTECTED
    Child3 child3;
    child3.pubChild3;
}