#include <iostream>
#include <string>
#include <vector>

struct Item
{
    int id;
    std::string name;
    int count;
};

int main()
{
    std::vector<Item> items;
    items.push_back({1, "Potion", 10});

    std::cout << items.front().id << ' '
              << items.front().name << ' '
              << items.front().count << '\n';
}
