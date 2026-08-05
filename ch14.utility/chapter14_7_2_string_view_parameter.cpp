#include <iostream>
#include <string>
#include <string_view>

bool StartsWithA(std::string_view text)
{
    return !text.empty() && text.front() == 'A';
}

class Player
{
public:
    explicit Player(std::string_view name)
        : name(name)
    {
    }

    const std::string& GetName() const
    {
        return name;
    }

private:
    std::string name;
};

int main()
{
    Player player{"Alice"};

    std::cout << std::boolalpha
              << StartsWithA(player.GetName())
              << '\n';
    std::cout << player.GetName() << '\n';
}
