#include <iostream>
#include <sstream>
#include <string>

struct PlayerData
{
    int id;
    std::string name;
    int hp;
};

std::string SerializePlayer(const PlayerData& player)
{
    std::ostringstream output;
    output << player.id << ','
           << player.name << ','
           << player.hp;

    return output.str();
}

int main()
{
    PlayerData player{1, "Knight", 100};
    std::cout << SerializePlayer(player) << '\n';
}
