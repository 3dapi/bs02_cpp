#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> items
    {
        {1001, "Potion"},
        {1002, ""},
        {1003, "Elixir"}
    };

    for (auto iterator = items.begin(); iterator != items.end();)
    {
        if (iterator->second.empty())
        {
            iterator = items.erase(iterator);
        }
        else
        {
            ++iterator;
        }
    }

    std::cout << items.size() << '\n';
}
