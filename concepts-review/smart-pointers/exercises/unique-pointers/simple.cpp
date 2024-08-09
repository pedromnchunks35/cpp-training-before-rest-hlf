#include <iostream>
#include <memory>
class Resource
{
public:
    Resource(int value) : value_(new int(value))
    {
        std::cout << "Resource acquired with value: " << (*value_) << "\n";
    }
    ~Resource()
    {
        std::cout << "Resource release with value: " << (*value_) << "\n";
        delete value_;
    }
    void display() const
    {
        std::cout << "Resource value: " << *value_ << "\n";
    }

private:
    //? we put the _ to mention that is a member variable, this is a good practise in c++
    int *value_;
};

int main()
{
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>(10);
    res1->display();
    std::unique_ptr<Resource> res2 = std::move(res1);
    res2->display();
    return 0;
}