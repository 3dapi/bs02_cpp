#include <any>
#include <iostream>
#include <string>

int main()
{
    std::any original = std::string{"large text"};
    std::any copied = original;

    std::any_cast<std::string&>(copied) += " copy";

    std::cout << std::any_cast<const std::string&>(original) << '\n';
    std::cout << std::any_cast<const std::string&>(copied) << '\n';
}
