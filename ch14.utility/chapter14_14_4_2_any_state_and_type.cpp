#include <any>
#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
    std::any value;
    std::cout << std::boolalpha << value.has_value() << '\n';
    std::cout << (value.type() == typeid(void)) << '\n';

    value.emplace<std::string>(5, '*');
    std::cout << (value.type() == typeid(std::string)) << '\n';
    std::cout << std::any_cast<const std::string&>(value) << '\n';

    value.reset();
    std::cout << value.has_value() << '\n';
}
