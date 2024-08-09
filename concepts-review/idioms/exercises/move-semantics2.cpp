#include <iostream>
#include <cstdint>
#include <string.h>
class String
{
public:
    String()
    {
        std::cout << "Constructed" << "\n";
        m_data = nullptr;
    }
    ~String()
    {
        std::cout << "Destructed" << "\n";
    }
    String(const char *string)
    {
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }
    void Print()
    {
        if (m_data != nullptr)
        {
            std::cout << std::string{m_data} << "\n";
        }
        else
        {
            std::cout << "No data" << "\n";
        }
    }
    String &operator=(String &&other) noexcept
    {
        std::cout << "We are making a move " << "\n";
        if (this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_size = 0;
            other.m_data = nullptr;
        }
        return *this;
    }

private:
    uint32_t m_size;
    char *m_data;
};
int main()
{
    String s = String("Hello world");
    String dest;
    s.Print();
    //? We need to call move because if it is equal only, it will invoke the copy
    //? MOVE operator
    dest = std::move(s);
    //? MOVE CONSTRUCTOR
    // String s = std::move(s);
    //? COPY
    // dest=s;
    dest.Print();
    s.Print();
}