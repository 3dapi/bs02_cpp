#include <format>
#include <iostream>
#include <string>

int main()
{
    std::string name = "Knight";
    int level = 12;

    std::string text = std::format(
        "Name: {}, Level: {}",
        name,
        level);

    std::cout << text << '\n';
}
