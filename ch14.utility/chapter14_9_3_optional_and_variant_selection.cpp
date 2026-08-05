#include <iostream>
#include <optional>
#include <string>
#include <variant>

using SettingValue = std::variant<int, double, std::string>;

std::optional<int> FindScore(bool found)
{
    if (found)
    {
        return 100;
    }

    return std::nullopt;
}

int main()
{
    std::optional<int> score = FindScore(false);
    SettingValue setting = std::string{"high"};

    std::cout << score.value_or(0) << '\n';

    std::visit(
        [](const auto& value)
        {
            std::cout << value << '\n';
        },
        setting);
}
