#include <iostream>
class EquilateralTriangle
{
    float a;
    float circunference;
    float area;

public:
    void setA(float length)
    {
        a = length;
        circunference = a + a + a;
        area = (1.73 * a * a) / 4;
    }
    //? HOW DO YOU STATE A FRIEND FUNCTION
    friend void PrintResults(EquilateralTriangle);
    friend class Homework;
};

void PrintResults(EquilateralTriangle et)
{
    std::cout << "cirucumference = " << et.circunference << "\n";
    std::cout << "area =" << et.area << "\n";
}

class Homework
{
public:
    void PrintResults(EquilateralTriangle et)
    {
        std::cout << "cirucumference = " << et.circunference << "\n";
        std::cout << "area =" << et.area << "\n";
    }
};

int main()
{
    EquilateralTriangle et;
    et.setA(3);
    PrintResults(et);
    Homework hw;
    hw.PrintResults(et);
}