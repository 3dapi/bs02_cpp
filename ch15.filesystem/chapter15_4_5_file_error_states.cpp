#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    const std::filesystem::path path = "chapter15_numbers.txt";

    {
        std::ofstream output{path};
        output << "10 20 invalid";
    }

    std::ifstream input{path};

    if (!input.is_open())
    {
        std::cerr << "File open failed\n";
        return 1;
    }

    int value = 0;
    while (input >> value)
    {
        std::cout << value << '\n';
    }

    if (input.bad())
    {
        std::cerr << "Device error while reading\n";
    }
    else if (!input.eof())
    {
        std::cerr << "Invalid number format\n";
    }

    input.close();
    std::filesystem::remove(path);
}
