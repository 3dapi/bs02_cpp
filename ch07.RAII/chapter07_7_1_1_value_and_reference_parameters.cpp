#include <iostream>
#include <string>

void PrintByValue(std::string name)
{
    std::cout << name << '\n';
}

void PrintByReference(const std::string& name)
{
    std::cout << name << '\n';
}

int main()
{
    std::string name = "Player";

    PrintByValue(name);
    PrintByReference(name);
}
