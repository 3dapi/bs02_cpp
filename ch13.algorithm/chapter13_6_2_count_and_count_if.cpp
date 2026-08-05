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
    std::vector<int> values{10, 20, 10, 30, 10};
    auto count = std::count(values.begin(), values.end(), 10);
    std::cout << count << '\n';

    std::vector<Player> players{
        {"Knight", 100},
        {"Mage", 0},
        {"Archer", 70}
    };

    auto aliveCount = std::count_if(
        players.begin(),
        players.end(),
        [](const Player& player)
        {
            return player.hp > 0;
        });

    std::cout << aliveCount << '\n';
}
