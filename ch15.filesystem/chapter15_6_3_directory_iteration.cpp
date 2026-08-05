#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path directory = "chapter15_assets";
    fs::create_directories(directory / "characters");

    {
        std::ofstream output{directory / "player.txt"};
        output << "player";
    }

    for (const fs::directory_entry& entry : fs::directory_iterator{directory})
    {
        std::cout << entry.path().filename() << '\n';
    }

    fs::remove_all(directory);
}
