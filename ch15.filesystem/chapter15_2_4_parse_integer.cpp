#include <iostream>
#include <optional>
#include <sstream>
#include <string>

std::optional<int> ParseInteger(const std::string& text)
{
    std::istringstream input{text};

    int value = 0;
    if (!(input >> value))
    {
        return std::nullopt;
    }

    input >> std::ws;
    if (!input.eof())
    {
        return std::nullopt;
    }

    return value;
}

int main()
{
    auto first = ParseInteger("100");
    auto second = ParseInteger("100abc");

    std::cout << first.value_or(-1) << '\n';
    std::cout << second.value_or(-1) << '\n';
}
