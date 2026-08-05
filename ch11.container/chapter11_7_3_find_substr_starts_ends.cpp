#include <iostream>
#include <string>

int main()
{
    std::string path = "assets/player.png";

    std::size_t position = path.find('/');
    std::size_t extensionPosition = path.rfind('.');

    if (position != std::string::npos &&
        extensionPosition != std::string::npos)
    {
        std::string extension = path.substr(extensionPosition + 1);

        std::cout << position << ' '
                  << extension << ' '
                  << std::boolalpha
                  << path.starts_with("assets/") << ' '
                  << path.ends_with(".png") << '\n';
    }
}
