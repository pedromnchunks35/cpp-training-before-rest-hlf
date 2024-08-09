#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.insert(vec.begin() + 2, 6);
    vec.erase(vec.begin());
    std::cout << "************" << "\n";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }
    std::cout << "************" << "\n";
    std::for_each(vec.begin(), vec.end(), [](int num)
                  { std::cout << num << "\n"; });
    std::cout << "************" << "\n";
    std::map<std::string, int> simpleMap;
    simpleMap.insert({"Pedro", 2});
    std::cout << simpleMap.at("Pedro") << "\n";
    std::cout << simpleMap["Pedro"] << "\n";
    std::cout << simpleMap["Elsa"] << "\n";
    std::cout << "************" << "\n";
    std::unordered_map<std::string, int> unMap;
    unMap.insert({"Pedro", 2});
    std::cout << unMap["Pedro"] << "\n";
    std::cout << "************" << "\n";
    std::list<int> doubleList;
    doubleList.push_back(2);
    doubleList.push_front(3);
    doubleList.push_front(4);
    doubleList.push_front(5);
    doubleList.pop_back();
    doubleList.pop_front();
    auto it = doubleList.begin();
    ++it;
    ++it;
    doubleList.erase(it);
}