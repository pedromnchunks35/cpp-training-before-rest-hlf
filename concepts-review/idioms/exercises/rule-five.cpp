#include <iostream>
#include <string.h>
class String
{
public:
    //? CONSTRUCTOR
    String()
    {
        m_data = 0;
        m_data = nullptr;
        std::cout << "Constructing.. " << "\n";
    }
    String(const char *string)
    {
        std::cout << "Constructing.. with args" << "\n";
        m_size = strlen(string);
        m_data = new char[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = string[i];
        }
    }
    //? Destructor
    ~String()
    {
        delete[] m_data;
        std::cout << "Destructing.. " << "\n";
    }
    //? Copy Constructor
    String(const String &other)
    {
        std::cout << "Copy constructor" << "\n";
        m_data = new char[other.m_size];
        m_size = other.m_size;
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }
    //?Move Constructor
    String(String &&other) noexcept
    {
        std::cout << "Move constructor" << "\n";
        if (this != &other)
        {
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_data = nullptr;
            other.m_size = 0;
        }
    }
    //? Copy operator
    String &operator=(const String &other) noexcept
    {
        std::cout << "Copy Operator" << "\n";
        if (this == &other)
        {
            return *this;
        }
        delete[] m_data;
        m_data = new char[other.m_size];
        m_size = other.m_size;
        m_size = other.m_size;
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
        return *this;
    }

    //? Move Operator
    String &operator=(String &&other) noexcept
    {
        std::cout << "Move Operator" << "\n";
        if (this == &other)
        {
            return *this;
        }
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0;
        return *this;
    }
    void Print()
    {
        if (m_data != nullptr)
        {
            std::cout << "Data " << std::string{m_data} << "\n";
        }
    }

private:
    char *m_data;
    int m_size;
};
int main()
{
    String s = String("Hello world");
    s.Print();
    String p = s;
    p.Print();
    //? This now contains the value of s
    String g = std::move(s);
    g.Print();
    String k;
    k = g;
    k = std::move(g);
}