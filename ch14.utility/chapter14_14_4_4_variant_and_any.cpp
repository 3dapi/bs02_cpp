#include <any>
#include <iostream>
#include <string>
#include <variant>

using SettingValue = std::variant<int, double, std::string>;

int main()
{
    SettingValue setting = 100;
    std::any dynamicValue = std::string{"plugin value"};

    std::visit(
        [](const auto& value)
        {
            std::cout << value << '\n';
        },
        setting);

    if (const std::string* text =
            std::any_cast<std::string>(&dynamicValue))
    {
        std::cout << *text << '\n';
    }
}
