#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{
    std::map<int, std::string> itemNames
    {
        {1001, "Potion"},
        {1002, "Ether"}
    };

    auto position = itemNames.find(1001);

    if (position != itemNames.end())
    {
        position->second = "High Potion";
    }

    auto node = itemNames.extract(1001);

    if (!node.empty())
    {
        node.key() = 2001;
        itemNames.insert(std::move(node));
    }

    for (const auto& entry : itemNames)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
}
