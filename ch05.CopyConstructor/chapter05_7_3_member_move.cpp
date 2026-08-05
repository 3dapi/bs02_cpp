#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Player
{
public:
    Player(std::string name, std::vector<int> items)
        : name(std::move(name)),
          items(std::move(items))
    {
    }

    Player(Player&& other) noexcept
        : name(std::move(other.name)),
          items(std::move(other.items))
    {
    }

    const std::string& GetName() const
    {
        return name;
    }

    std::size_t GetItemCount() const
    {
        return items.size();
    }

private:
    std::string name;
    std::vector<int> items;
};

int main()
{
    Player first("Knight", {1, 2, 3});
    Player second(std::move(first));

    std::cout << second.GetName() << '\n';
    std::cout << second.GetItemCount() << '\n';
}
