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
        {"Knight", 100},
        {"Mage", 80},
        {"Archer", 100}
    };

    std::stable_sort(
        players.begin(),
        players.end(),
        [](const Player& left, const Player& right)
        {
            return left.score > right.score;
        });

    for (const Player& player : players)
    {
        std::cout << player.name << ' ' << player.score << '\n';
    }
}
