#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    const std::filesystem::path path = "chapter15_data.txt";

    {
        std::ofstream output{path};
        output << "first line\n";
    }

    std::fstream file{
        path,
        std::ios::in | std::ios::out | std::ios::ate};

    file.seekg(0);
    std::string line;
    std::getline(file, line);

    file.clear();
    file.seekp(0, std::ios::end);
    file << "new line\n";
    file.close();

    std::cout << line << '\n';
    std::filesystem::remove(path);
}
