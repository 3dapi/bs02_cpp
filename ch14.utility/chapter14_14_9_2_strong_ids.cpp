#include <iostream>

struct PlayerId
{
    int value;
};

struct ItemId
{
    int value;
};

void EquipItem(PlayerId playerId, ItemId itemId)
{
    std::cout << playerId.value << ' '
              << itemId.value << '\n';
}

int main()
{
    PlayerId playerId{100};
    ItemId itemId{200};

    EquipItem(playerId, itemId);
}
