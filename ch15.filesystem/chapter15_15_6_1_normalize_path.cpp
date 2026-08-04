#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path path = "assets/characters/../items/potion.png";
    fs::path normalized = path.lexically_normal();
    normalized.replace_extension(".bin");

    std::cout << normalized << '\n';
}
