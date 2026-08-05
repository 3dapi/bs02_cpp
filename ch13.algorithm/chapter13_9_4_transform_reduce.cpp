#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

struct Player
{
    int score;
};

int main()
{
    std::vector<Player> players{{100}, {80}, {90}};

    int totalScore = std::transform_reduce(
        players.begin(),
        players.end(),
        0,
        std::plus<>{},
        [](const Player& player)
        {
            return player.score;
        });

    std::cout << totalScore << '\n';
}
