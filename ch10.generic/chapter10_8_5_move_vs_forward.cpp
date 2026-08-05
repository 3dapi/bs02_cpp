#include <iostream>
#include <string>
#include <utility>

void Use(const std::string& value)
{
    std::cout << "lvalue: " << value << '\n';
}

void Use(std::string&& value)
{
    std::cout << "rvalue: " << value << '\n';
}

template <typename T>
void ForwardToUse(T&& value)
{
    Use(std::forward<T>(value));
}

template <typename T>
void RelayWithMove(T&& value)
{
    Use(std::move(value));
}

class Player
{
public:
    explicit Player(std::string name)
        : name(std::move(name))
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
    std::string name = "Knight";

    ForwardToUse(name);
    ForwardToUse(std::string("Mage"));

    RelayWithMove(name);

    Player player("Rogue");
    std::cout << player.GetName() << '\n';
}
