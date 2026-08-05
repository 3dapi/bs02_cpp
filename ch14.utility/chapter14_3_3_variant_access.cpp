#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<int, double, std::string> value = 3.5;

    std::cout << value.index() << '\n';
    std::cout << std::boolalpha
              << std::holds_alternative<double>(value)
              << '\n';

    std::cout << std::get<1>(value) << '\n';

    if (double* number = std::get_if<double>(&value))
    {
        *number *= 2.0;
        std::cout << *number << '\n';
    }

    try
    {
        std::cout << std::get<std::string>(value) << '\n';
    }
    catch (const std::bad_variant_access&)
    {
        std::cout << "wrong alternative\n";
    }
}
