#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path baseDirectory = "assets";
    fs::path fileName = "knight.png";
    fs::path path = baseDirectory / "textures" / fileName;

    auto nativePath = path.native();
    std::string text = path.string();
    std::string generic = path.generic_string();

    std::cout << nativePath << '\n';
    std::cout << text << '\n';
    std::cout << generic << '\n';
}
