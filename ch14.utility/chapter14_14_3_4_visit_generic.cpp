#include <iostream>
#include <string>
#include <type_traits>
#include <variant>

int main()
{
    std::variant<int, double, std::string> value = std::string{"hello"};

    std::visit(
        [](const auto& stored)
        {
            using T = std::remove_cvref_t<decltype(stored)>;

            if constexpr (std::is_same_v<T, int>)
            {
                std::cout << "integer: " << stored << '\n';
            }
            else if constexpr (std::is_same_v<T, double>)
            {
                std::cout << "real: " << stored << '\n';
            }
            else
            {
                std::cout << "text: " << stored << '\n';
            }
        },
        value);
}
