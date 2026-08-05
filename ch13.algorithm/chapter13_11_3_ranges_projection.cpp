#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
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
        {"Archer", 90}
    };

    std::ranges::sort(players, std::greater<>{}, &Player::score);

    auto position = std::ranges::find(
        players,
        std::string{"Mage"},
        &Player::name);

    if (position != players.end())
    {
        std::cout << position->name << ' ' << position->score << '\n';
    }
}
