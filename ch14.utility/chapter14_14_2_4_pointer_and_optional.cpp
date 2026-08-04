#include <iostream>
#include <optional>
#include <vector>

class Player
{
public:
    Player(int id, int hp)
        : id(id), hp(hp)
    {
    }

    int GetId() const
    {
        return id;
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int id;
    int hp;
};

Player* FindPlayer(std::vector<Player>& players, int id)
{
    for (Player& player : players)
    {
        if (player.GetId() == id)
        {
            return &player;
        }
    }

    return nullptr;
}

std::optional<int> FindHp(const std::vector<Player>& players, int id)
{
    for (const Player& player : players)
    {
        if (player.GetId() == id)
        {
            return player.GetHp();
        }
    }

    return std::nullopt;
}

int main()
{
    std::vector<Player> players;
    players.emplace_back(1, 100);
    players.emplace_back(2, 80);

    Player* player = FindPlayer(players, 2);
    std::optional<int> hp = FindHp(players, 2);

    if (player != nullptr)
    {
        std::cout << player->GetHp() << '\n';
    }

    std::cout << hp.value_or(0) << '\n';
}
