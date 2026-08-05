#include <iostream>

class Inventory
{
public:
    enum class EquipResult
    {
        Success,
        ItemNotFound,
        LevelTooLow,
        SlotUnavailable
    };

    EquipResult EquipItem(int itemId)
    {
        if (itemId != 1001)
        {
            return EquipResult::ItemNotFound;
        }

        return EquipResult::Success;
    }
};

int main()
{
    Inventory inventory;
    const Inventory::EquipResult result = inventory.EquipItem(1001);

    switch (result)
    {
    case Inventory::EquipResult::Success:
        std::cout << "success\n";
        break;

    case Inventory::EquipResult::ItemNotFound:
        std::cout << "item not found\n";
        break;

    case Inventory::EquipResult::LevelTooLow:
        std::cout << "level too low\n";
        break;

    case Inventory::EquipResult::SlotUnavailable:
        std::cout << "slot unavailable\n";
        break;
    }
}
