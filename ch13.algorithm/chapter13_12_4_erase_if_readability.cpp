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
    std::vector<Player> players{
        {"Knight", 100},
        {"Mage", 0},
        {"Archer", 70}
    };

    std::erase_if(
        players,
        [](const Player& player)
        {
            return player.hp == 0;
        });

    for (const Player& player : players)
    {
        std::cout << player.name << '\n';
    }
}
