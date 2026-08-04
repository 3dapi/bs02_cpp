#include <functional>
#include <iostream>
#include <set>

struct Player
{
    int id;
    int score;
};

struct ComparePlayer
{
    bool operator()(const Player& left, const Player& right) const
    {
        if (left.score != right.score)
        {
            return left.score > right.score;
        }

        return left.id < right.id;
    }
};

int main()
{
    std::set<int, std::greater<int>> values{10, 30, 20};
    std::set<Player, ComparePlayer> ranking
    {
        {1, 100},
        {2, 200},
        {3, 100}
    };

    for (int value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';

    for (const Player& player : ranking)
    {
        std::cout << player.id << ':' << player.score << ' ';
    }
    std::cout << '\n';
}
