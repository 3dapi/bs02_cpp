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

    std::sort(
        players.begin(),
        players.end(),
        [](const Player& left, const Player& right)
        {
            if (left.score != right.score)
            {
                return left.score > right.score;
            }

            return left.name < right.name;
        });

    for (const Player& player : players)
    {
        std::cout << player.name << ' ' << player.score << '\n';
    }
}
