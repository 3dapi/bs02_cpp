#include <format>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
    std::string log;

    std::format_to(
        std::back_inserter(log),
        "Player {} joined with level {}\n",
        "Knight",
        12);

    std::format_to(
        std::back_inserter(log),
        "Current HP: {}\n",
        100);

    std::cout << log;
}
