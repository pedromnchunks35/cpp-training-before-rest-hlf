#include <mutex>
#include <iostream>
#include <thread>
#include <chrono>
class Muta
{
public:
    Muta() {}
    void racing(int id)
    {
        mutex.lock();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Im here " << id << "\n";
        mutex.unlock();
    }
    void racing2(int id)
    {
        std::lock_guard<std::mutex> guard(mutex);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Im here " << id << "\n";
    }

private:
    std::mutex mutex;
};
int main()
{
    Muta muta;
    muta.racing(1);
    std::thread t1(&Muta::racing, &muta, 1);
    std::thread t2(&Muta::racing, &muta, 2);
    t1.join();
    t2.join();
    std::thread t3(&Muta::racing2, &muta, 3);
    std::thread t4(&Muta::racing2, &muta, 4);
    t3.join();
    t4.join();
    return 0;
}