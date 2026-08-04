#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    const std::filesystem::path path = "chapter15_position.bin";

    {
        std::ofstream output{path, std::ios::binary};
        output.write("0123456789", 10);
    }

    std::ifstream input{path, std::ios::binary};
    input.seekg(0, std::ios::end);
    const std::streampos end = input.tellg();

    input.seekg(4, std::ios::beg);
    char value = '\0';
    input.get(value);

    std::cout << end << ' ' << value << '\n';
    input.close();
    std::filesystem::remove(path);
}
