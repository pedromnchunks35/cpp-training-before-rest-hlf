#include <iostream>
#include <memory>
class Resource
{
private:
    std::string name;

public:
    void show()
    {
        std::cout << name << "\n";
    }
    Resource(std::string name)
    {
        this->name = name;
        std::cout << "Resource created" << "\n";
    }
    ~Resource()
    {
        std::cout << "Resourse is beeing deleted" << "\n";
    }
};
int main()
{
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("Pedro");

    {
        // Create a second shared_ptr managing the same Resource object
        std::shared_ptr<Resource> ptr2 = ptr1;
        ptr2->show();

        // Create a third shared_ptr managing the same Resource object
        std::shared_ptr<Resource> ptr3 = ptr1;
        ptr3->show();

        // Print the reference count
        std::cout << "Reference count: " << ptr1.use_count() << std::endl;
    } // ptr2 and ptr3 go out of scope and are destroyed

    // Print the reference count after ptr2 and ptr3 are out of scope
    std::cout << "Reference count after ptr2 and ptr3 are out of scope: " << ptr1.use_count() << std::endl;
    //? NORMAL POINTER IT DOES NOT GET DELETED UNFORTENELY
    Resource *j = new Resource("Elsa");
    delete j;
    //? IF WE DELETE TWICE IT GETS A ERROR BECAUSE IT REALLY GOT DELETED
    /* delete j; */
}