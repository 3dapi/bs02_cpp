#include <format>
#include <iostream>
#include <string>

int main()
{
    int level = 12;
    std::string name = "Knight";

    std::cout << std::format(
        "{1} has level {0}",
        level,
        name) << '\n';
}
