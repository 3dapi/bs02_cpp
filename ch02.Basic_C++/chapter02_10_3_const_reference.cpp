#include <iostream>
#include <string>

void Print(const std::string& text)
{
    std::cout << text << '\n';
}

int main()
{
    std::string first = "Hello";
    const std::string second = "C++";
    Print(first);
    Print(second);
    Print(std::string("Temporary"));
}
