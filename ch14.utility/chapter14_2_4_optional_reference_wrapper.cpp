#include <functional>
#include <iostream>
#include <optional>
#include <vector>

struct Player
{
    int id;
    int hp;
};

std::optional<std::reference_wrapper<Player>> FindPlayerReference(
    std::vector<Player>& players,
    int id)
{
    for (Player& player : players)
    {
        if (player.id == id)
        {
            return std::ref(player);
        }
    }

    return std::nullopt;
}

int main()
{
    std::vector<Player> players{{1, 100}, {2, 80}};
    auto result = FindPlayerReference(players, 2);

    if (result)
    {
        result->get().hp += 20;
        std::cout << players[1].hp << '\n';
    }
}
