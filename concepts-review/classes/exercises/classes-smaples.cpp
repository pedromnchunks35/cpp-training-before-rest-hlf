#include <iostream>
class Parent
{
public:
    Parent() {}
    virtual void print()
    {
        std::cout << "Hello world" << "\n";
    }
    virtual void print3()
    {
        std::cout << "Another print" << "\n";
    }
};
class Child : virtual public Parent
{
public:
    Child() {}
    void print() override
    {
        std::cout << "Hello from the child" << "\n";
    }
    virtual void print2()
    {
        std::cout << "Hello from child print2" << "\n";
    }
};
class Child2 : virtual public Parent
{
public:
    Child2() {}
    void print() override
    {
        std::cout << "Hello from the child" << "\n";
    }
    virtual void print2()
    {
        std::cout << "Hello from child print2" << "\n";
    }
};
class grandChild : public Child2, public Child
{
public:
    grandChild() {}
    void print() override
    {
        // Explicitly override to resolve ambiguity
        Child::print(); // Or Child2::print() based on desired behavior
    }
    void print2() override
    {
        Child2::
            print2();
    }
};
int main()
{
    grandChild g;
    //? WE STILL MUST SPECIFY WHICH PRINTS WE WISH TO USE FROM THOSE 2 CLASSES BECAUSE IT HAS AMBIGUITY
    g.print();
    g.print2();
    //? VIRTUAL IN INHERITANCE SOLVES THIS PROBLEM SO WE DONT HAVE THIS METHOD DUPLICATED
    g.print3();
}