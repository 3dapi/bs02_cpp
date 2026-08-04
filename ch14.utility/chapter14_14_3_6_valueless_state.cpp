#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<int, std::string> value = std::string{"ready"};

    std::cout << std::boolalpha
              << value.valueless_by_exception()
              << '\n';

    if (value.index() != std::variant_npos)
    {
        std::cout << "active alternative: " << value.index() << '\n';
    }
}
