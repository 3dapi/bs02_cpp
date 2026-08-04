#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> items
    {
        {1001, "Potion"},
        {1002, "Ether"}
    };

    std::string& name = items.at(1001);
    items.reserve(2000);

    std::cout << name << '\n';
}
