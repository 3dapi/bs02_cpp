#include <iostream>
#include <string>

int main()
{
    std::string first = "Hello";
    std::string second(5, '*');
    std::string third = first;

    std::string name;
    name = "Alice";

    std::cout << first << ' '
              << second << ' '
              << third << ' '
              << name.size() << ' '
              << name.length() << '\n';
}
