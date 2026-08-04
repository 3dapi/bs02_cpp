#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Player
{
    std::string name;
    int hp;
};

int main()
{
    Player knight{"Knight", 100};
    Player mage{"Mage", 80};
    Player archer{"Archer", 90};

    std::vector<std::reference_wrapper<Player>> party{
        knight,
        mage,
        archer
    };

    for (Player& player : party)
    {
        player.hp += 10;
    }

    std::cout << knight.hp << ' '
              << mage.hp << ' '
              << archer.hp << '\n';
}
