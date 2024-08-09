#include <iostream>
void PrintSum(int a, int b)
{
    std::cout << a << "+" << b << "=" << (a + b) << "\n";
}
int main()
{   
    //? the behavior is equal in C++17 but its unpredictable behavior before that
    //? The behavior depends of the compiler and the version of C++
    int value = 0;
    PrintSum(value++, value++);
    PrintSum(++value, ++value);
}