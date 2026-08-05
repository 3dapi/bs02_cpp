#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

struct ItemKey
{
    int category;
    int id;

    bool operator==(const ItemKey&) const = default;
};

struct ItemKeyHash
{
    std::size_t operator()(const ItemKey& key) const noexcept
    {
        std::size_t first = std::hash<int>{}(key.category);
        std::size_t second = std::hash<int>{}(key.id);
        return first ^ (second << 1);
    }
};

int main()
{
    std::unordered_map<ItemKey, std::string, ItemKeyHash> itemNames;
    itemNames.insert({ItemKey{1, 1001}, "Potion"});

    std::cout << itemNames.at(ItemKey{1, 1001}) << '\n';
}
