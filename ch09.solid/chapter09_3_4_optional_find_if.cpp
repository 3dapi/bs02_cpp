#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <algorithm>

struct Item
{
    int id;
    std::string name;
};

class Inventory
{
protected:
    // 외부에서 접근제한. (안전함)
    std::vector<Item> items;
    int value{};

public:
    Inventory(std::initializer_list<Item> init_list, int v): items{init_list}, value{v} {}

    void Add(Item item)
    {
        // std::move를 사용, std::string 복사 방지.
        items.push_back(std::move(item));
    }
    //
    // 극한의 성능.
    //void Add(const Item& item)
    //{
    //  items.emplace_back(item);
    //}
    //
    //void Add(Item&& item)
    //{
    //  items.emplace_back(std::move(item));
    //}

    std::optional<Item> FindById(int id) const
    {
        if(auto it = std::find_if(items.begin(), items.end(), [id](const auto& i)
        {
            return i.id == id;
        }); it != items.end())
        {
            return *it;
        }
        return std::nullopt;
    }
};

int main()
{
    // std::initializer_list를 활용한 일괄 초기화.
    Inventory inventory
    {
        {
              {1001, "Potion"}
            , {2001, "Iron Sword"}
            , {5001, "Bronze armor"}
        },
        1235678,
    };

    inventory.Add({4001, "Health Potion"});
    Item item{3001, "Wooden Shield"};
    inventory.Add(item);

    if(auto item = inventory.FindById(5001))
    {
        std::cout << item->name << '\n';
    }
}
