#include <compare>
#include <iostream>
#include <set>

struct ItemKey
{
    int category;
    int id;

    auto operator<=>(const ItemKey&) const = default;
};

int main()
{
    std::set<ItemKey> keys;

    keys.insert({1, 1002});
    keys.insert({1, 1001});
    keys.insert({2, 1001});

    for (const ItemKey& key : keys)
    {
        std::cout << key.category << ':' << key.id << ' ';
    }
    std::cout << '\n';
}
