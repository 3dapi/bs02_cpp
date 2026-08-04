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
    std::vector<Player> players{
        {"Knight", 100},
        {"Mage", 0},
        {"Archer", 70}
    };

    bool allAlive = std::all_of(
        players.begin(),
        players.end(),
        [](const Player& player)
        {
            return player.hp > 0;
        });

    bool hasDefeatedPlayer = std::any_of(
        players.begin(),
        players.end(),
        [](const Player& player)
        {
            return player.hp == 0;
        });

    bool noInvalidHp = std::none_of(
        players.begin(),
        players.end(),
        [](const Player& player)
        {
            return player.hp < 0;
        });

    std::cout << std::boolalpha
              << allAlive << ' '
              << hasDefeatedPlayer << ' '
              << noInvalidHp << '\n';
}
