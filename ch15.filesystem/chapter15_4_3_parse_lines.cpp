#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

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
    const std::filesystem::path path = "chapter15_players.txt";

    {
        std::ofstream output{path};
        output << "1 Knight 100\ninvalid line\n2 Mage 80\n";
    }

    std::ifstream input{path};
    std::vector<PlayerData> players;
    std::string line;
    int lineNumber = 0;

    while (std::getline(input, line))
    {
        ++lineNumber;

        PlayerData player{};
        if (!ParsePlayer(line, player))
        {
            std::cerr << "Invalid line: " << lineNumber << '\n';
            continue;
        }

        players.push_back(std::move(player));
    }

    std::cout << players.size() << '\n';
    input.close();
    std::filesystem::remove(path);
}
