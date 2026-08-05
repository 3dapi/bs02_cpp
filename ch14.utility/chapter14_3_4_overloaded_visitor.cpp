#include <iostream>
#include <string>
#include <variant>

template <typename... Functions>
struct Overloaded : Functions...
{
    using Functions::operator()...;
};

template <typename... Functions>
Overloaded(Functions...) -> Overloaded<Functions...>;

int main()
{
    std::variant<int, double, std::string> value = std::string{"hello"};

    std::visit(
        Overloaded{
            [](int number)
            {
                std::cout << "int: " << number << '\n';
            },
            [](double number)
            {
                std::cout << "double: " << number << '\n';
            },
            [](const std::string& text)
            {
                std::cout << "string: " << text << '\n';
            }
        },
        value);
}
