#include <iostream>
#include <string>
#include <utility>

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

    Player first(name);
    Player second("Mage");

    std::cout << first.GetName() << '\n';
    std::cout << second.GetName() << '\n';
}
