#include <iostream>
#include <set>
#include <string>

struct Player
{
    int id;
    std::string name;
    int score;
};

struct CompareByScore
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

struct CompareByName
{
    bool operator()(const Player& left, const Player& right) const
    {
        if (left.name != right.name)
        {
            return left.name < right.name;
        }

        return left.id < right.id;
    }
};

int main()
{
    Player first{1, "Carol", 100};
    Player second{2, "Alice", 200};
    Player third{3, "Alice", 100};

    std::set<Player, CompareByScore> scoreRanking{first, second, third};
    std::set<Player, CompareByName> nameIndex{first, second, third};

    std::cout << scoreRanking.begin()->id << '\n';
    std::cout << nameIndex.begin()->id << '\n';
}
