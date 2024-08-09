#include <iostream>
#include <memory>
class Resource
{
private:
    std::string name;

public:
    Resource(std::string name)
    {
        this->name = name;
    }
    ~Resource()
    {
        std::cout << "Resource released" << "\n";
    }
    std::string &getName()
    {
        return name;
    }
};
int main()
{
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("Elsa");
    Resource *value = ptr1.get();
    std::cout << ptr1.use_count() << "\n";
    std::cout << value->getName() << "\n";
    std::weak_ptr ptr1_weak = ptr1;
     std::cout << ptr1.use_count() << "\n";
    std::shared_ptr ptr3 = ptr1;
    std::cout << ptr3.use_count() << "\n";
    ptr1_weak.reset();
    if (auto lockedPtr = ptr1_weak.lock())
    {
        std::cout << lockedPtr.use_count() << "\n";
    }
    else
    {
        std::cout << "No reference" << "\n";
    }
    std::cout << ptr3.use_count() << "\n";
}