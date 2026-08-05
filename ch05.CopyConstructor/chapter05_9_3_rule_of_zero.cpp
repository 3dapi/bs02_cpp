#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Inventory
{
public:
    void SetOwner(std::string owner)
    {
        this->owner = std::move(owner);
    }

    void AddItem(const std::string& item)
    {
        items.push_back(item);
    }

    std::size_t GetItemCount() const
    {
        return items.size();
    }

private:
    std::string owner;
    std::vector<std::string> items;
};

int main()
{
    Inventory first;
    first.SetOwner("Knight");
    first.AddItem("Sword");

    Inventory second = first;
    Inventory third = std::move(first);

    std::cout << second.GetItemCount() << '\n';
    std::cout << third.GetItemCount() << '\n';
}
