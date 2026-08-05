#include <iostream>
#include <sstream>
#include <string>
#include <utility>

struct PlayerData
{
    int id;
    std::string name;
    int hp;
};

bool ParsePlayer(const std::string& text, PlayerData& player)
{
    std::istringstream input{text};

    int id = 0;
    std::string name;
    int hp = 0;

    if (!(input >> id >> name >> hp))
    {
        return false;
    }

    player = PlayerData{id, std::move(name), hp};
    return true;
}

int main()
{
    PlayerData player{};

    if (ParsePlayer("1 Knight 100", player))
    {
        std::cout << player.id << ' '
                  << player.name << ' '
                  << player.hp << '\n';
    }
}
