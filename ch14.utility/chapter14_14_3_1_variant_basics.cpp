#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<int, double, std::string> value;
    std::cout << value.index() << ' ' << std::get<int>(value) << '\n';

    value = 3.5;
    std::cout << value.index() << ' ' << std::get<double>(value) << '\n';

    value = std::string{"hello"};
    std::cout << value.index() << ' ' << std::get<std::string>(value) << '\n';
}
