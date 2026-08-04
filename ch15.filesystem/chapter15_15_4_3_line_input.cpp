#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    const std::filesystem::path path = "chapter15_config.txt";

    {
        std::ofstream output{path};
        output << "width=1920\nheight=1080\n";
    }

    std::ifstream input{path};
    std::string line;

    while (std::getline(input, line))
    {
        std::cout << line << '\n';
    }

    if (!input.eof())
    {
        std::cerr << "Failed while reading config.txt\n";
    }

    input.close();
    std::filesystem::remove(path);
}
