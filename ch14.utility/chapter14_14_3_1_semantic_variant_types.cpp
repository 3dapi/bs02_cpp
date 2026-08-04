#include <iostream>
#include <variant>

struct PlayerId
{
    int value;
};

struct ItemId
{
    int value;
};

int main()
{
    std::variant<PlayerId, ItemId> id = PlayerId{100};

    if (const PlayerId* playerId = std::get_if<PlayerId>(&id))
    {
        std::cout << playerId->value << '\n';
    }

    id = ItemId{200};

    if (const ItemId* itemId = std::get_if<ItemId>(&id))
    {
        std::cout << itemId->value << '\n';
    }
}
