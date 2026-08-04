#include <any>
#include <iostream>
#include <string>

int main()
{
    std::any value = 10;
    std::cout << std::any_cast<int>(value) << '\n';

    value = 3.5;
    std::cout << std::any_cast<double>(value) << '\n';

    value = std::string{"hello"};
    std::cout << std::any_cast<std::string>(value) << '\n';
}
