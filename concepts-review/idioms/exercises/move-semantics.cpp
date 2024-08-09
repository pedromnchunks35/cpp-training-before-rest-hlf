#include <iostream>
#include <cstdint>
#include <string.h>
class String
{
public:
    String() = default;
    String(const char *string)
    {
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }
    String(String &&other) noexcept
    {
        std::cout << "Moved!!" << "\n";
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_data = nullptr;
    }
    //? Copy constructor
    String(const String &other)
    {
        printf("Copied \n");
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }
    ~String()
    {
        std::cout << "Destroyed" << "\n";
        delete m_data;
    }
    void Print()
    {
        for (uint32_t i = 0; i < m_size; i++)
        {
            printf("%c", m_data[i]);
        }
    }

private:
    char *m_data;
    uint32_t m_size;
};

class Entity
{
public:
    Entity(const String &name) : m_name(name)
    {
    }
    //? WE NEED TO MAKE THE EXPLICIT MOVE THE VARIABLE TO ACTUALLY MOVE
    Entity(const String &&name) : m_name((String &&)name)
    {
        //? WE ARE PASSING A R VALUE LIKE THIS
    }
    void Printname()
    {
        m_name.Print();
    }

private:
    String m_name;
};
int main()
{
    //? WE NEED A WAY TO COPY A STRING HERE SO WE NEED A COPY CONSTRUCTOR
    //? This is bad because we are allocating memory, which is not desirable
    Entity entity(String("Cherno"));
    std::cin.get();
}