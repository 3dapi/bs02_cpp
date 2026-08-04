#include <iostream>
#include <string>
#include <variant>

using Result = std::variant<std::monostate, int, std::string>;

int main()
{
    Result result;

    if (std::holds_alternative<std::monostate>(result))
    {
        std::cout << "empty\n";
    }

    result = 100;
    std::cout << std::get<int>(result) << '\n';
}
