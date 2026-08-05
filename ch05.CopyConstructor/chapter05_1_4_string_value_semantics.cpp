#include <iostream>
#include <string>

int main()
{
    std::string first = "Player";
    std::string second = first;

    second.append("_Two");

    std::cout << first << '\n';
    std::cout << second << '\n';
}
