#include <iostream>
#include <string>
#include <string_view>

std::string_view FileName(std::string_view path)
{
    std::size_t position = path.find_last_of("/\\");

    if (position == std::string_view::npos)
    {
        return path;
    }

    return path.substr(position + 1);
}

int main()
{
    std::string path = "assets/player.png";
    std::string_view fileName = FileName(path);

    std::cout << fileName << '\n';
}
