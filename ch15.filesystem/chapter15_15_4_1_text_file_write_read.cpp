#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    const std::filesystem::path path = "chapter15_player.txt";

    {
        std::ofstream output{path};
        if (!output)
        {
            return 1;
        }

        output << 1 << ' '
               << "Knight" << ' '
               << 100 << '\n';
    }

    std::ifstream input{path};
    int id = 0;
    std::string name;
    int hp = 0;

    if (input >> id >> name >> hp)
    {
        std::cout << id << ' ' << name << ' ' << hp << '\n';
    }

    input.close();
    std::filesystem::remove(path);
}
