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
    std::cout << items.load_factor() << ' '
              << items.max_load_factor() << '\n';

    items.reserve(1000);

    std::cout << name << '\n';
    std::cout << items.bucket_count() << '\n';
}
