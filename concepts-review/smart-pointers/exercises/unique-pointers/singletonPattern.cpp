#include <iostream>
#include <memory>
#include <mutex>
class Singleton
{
public:
    static Singleton *get_instance()
    {
        static Singleton *instance;
        static std::mutex mutex;
        static std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr)
        {
            std::string newName = "hello";
            instance = new Singleton();
        }
        return instance;
    }
    void show()
    {
        std::cout << this << "\n";
    }
    void setName(std::string newName)
    {
        name = newName;
    }
    void getName()
    {
        std::cout << "Im the name: " << this->name << "\n";
    }

private:
    Singleton()
    {
        std::cout << "Resource created " << "\n";
    }
    ~Singleton()
    {
        std::cout << "Resource deleted " << "\n";
    }
    Singleton(const Singleton &) = delete;
    static std::string name;
    Singleton &operator=(const Singleton &) = delete;
};
std::string Singleton::name = "";
int main()
{
    Singleton *s1 = Singleton::get_instance();
    s1->show();
    s1->getName();
    Singleton *s2 = Singleton::get_instance();
    s2->setName("Pedro");
    s1->show();
    s1->getName();
}