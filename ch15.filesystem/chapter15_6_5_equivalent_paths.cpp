#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path path = "chapter15_equivalent.txt";
    std::ofstream{path} << "data";

    fs::path first = path;
    fs::path second = fs::absolute(path);

    std::cout << std::boolalpha
              << fs::equivalent(first, second) << '\n';

    fs::remove(path);
}
