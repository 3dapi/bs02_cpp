#include <algorithm>
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
    std::vector<int> values{10, 20, 30, 20};
    auto valuePosition = std::find(values.begin(), values.end(), 20);

    if (valuePosition != values.end())
    {
        std::cout << *valuePosition << '\n';
    }

    std::vector<Player> players{
        {"Knight", 100},
        {"Mage", 0},
        {"Archer", 70}
    };

    auto playerPosition = std::find_if(
        players.begin(),
        players.end(),
        [](const Player& player)
        {
            return player.hp == 0;
        });

    if (playerPosition != players.end())
    {
        std::cout << playerPosition->name << '\n';
    }
}
