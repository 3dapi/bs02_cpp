#include <iostream>
#include <optional>

int main()
{
    std::optional<int> value;
    std::cout << std::boolalpha << value.has_value() << '\n';

    value = 10;
    std::cout << *value << '\n';

    value = 20;
    std::cout << *value << '\n';

    value.reset();
    std::cout << value.has_value() << '\n';
}
