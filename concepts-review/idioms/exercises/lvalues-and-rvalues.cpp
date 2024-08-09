#include <iostream>
int GetValue()
{
    return 10;
}
int &Something()
{
    static int value = 10;
    return value;
}

void SetValue(int value)
{
}
void RvalueDetecter(std::string &k)
{
}
void PassARValue(std::string &&k)
{
    std::cout << "This is our R value: " << k << "\n";
}
int main()
{
    //? LVALUE IS THE LEFT AND THE RVALUE IS RIGHT
    //? LVALUE IS MEMORY, RIGHT VALUE IS A VALUE
    int i = 10;
    //? BOTH LVALUE
    int a = i;
    //? RVALUES CANNOT HAVE VALUES ASSIGNED TO IT
    int c = GetValue();
    //? WE CANT CREATE A LVALUE NORMAL, WE CAN ONLY DO IT IF IT IS CONST
    const int &k = 20;
    // THIS OF COURSE DOES NOT WORK
    // GetValue() = c;
    //? THIS NOW BECOMES A LVALUE
    //? THIS IS A LEFT VALUE REFERENCE
    Something() = 5;
    //? WE CAN USE THE SETVALUE FUNCTION WITH A LVALUE AND A RVALUE
    SetValue(i);
    SetValue(3);
    //? The most easier way to spot a Rvalue is to try to put in a Lvalue (a reference input)
    //? IN THE FUNCTION DOWN WE CANT PASS R VALUES,ONLY L VALUES
    std::string hello = "Kkk";
    RvalueDetecter(hello);
    std::string hello2 = "kkk2";
    PassARValue(hello + hello2);
    //? R VALUES ARE BASICLY TEMP VALUES
    //? L VALUES ARE BASICLY VARIABLES THAT TAKE UP MEMORY
    //? WE CAN PASS R VALUES TO CONST REFERENCE VALUES
    //? WE CAN PASS R VALUES TO && 
}