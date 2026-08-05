#include <iostream>
#include <map>

int main()
{
    std::map<int, int> prices
    {
        {1001, 50},
        {1002, 80}
    };

    for (auto& [id, price] : prices)
    {
        price += 10;
        std::cout << id << ": " << price << '\n';
    }
}
