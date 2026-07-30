#include <iostream>
#include <limits>
#include <string>

int main()
{
    int age = 0;
    std::string name;
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << name << ' ' << age << '\n';
}
