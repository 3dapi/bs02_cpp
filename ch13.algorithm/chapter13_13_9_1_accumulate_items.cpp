#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct Item
{
    std::string name;
    int price;
};

int main()
{
    std::vector<Item> items{
        {"Potion", 100},
        {"Ether", 250},
        {"Elixir", 500}
    };

    int totalPrice = std::accumulate(
        items.begin(),
        items.end(),
        0,
        [](int total, const Item& item)
        {
            return total + item.price;
        });

    std::cout << totalPrice << '\n';
}
