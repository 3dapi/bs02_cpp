#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path directory = "save";
    fs::path fileName = "player.dat";
    fs::path fullPath = directory / fileName;

    std::cout << fullPath << '\n';
    std::cout << fullPath.filename() << '\n';
    std::cout << fullPath.stem() << '\n';
    std::cout << fullPath.extension() << '\n';
    std::cout << fullPath.parent_path() << '\n';
}
