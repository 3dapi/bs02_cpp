#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Player
{
    std::string name;
    int score;
};

int main()
{
    std::vector<Player> players{
        {"Mage", 80},
        {"Archer", 90},
        {"Knight", 100}
    };

    int score = 100;

    auto position = std::lower_bound(
        players.begin(),
        players.end(),
        score,
        [](const Player& player, int value)
        {
            return player.score < value;
        });

    if (position != players.end())
    {
        std::cout << position->name << '\n';
    }
}
