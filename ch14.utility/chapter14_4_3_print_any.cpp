#include <any>
#include <iostream>
#include <string>

void PrintAny(const std::any& value)
{
    if (const int* number = std::any_cast<int>(&value))
    {
        std::cout << *number << '\n';
    }
    else if (const double* number = std::any_cast<double>(&value))
    {
        std::cout << *number << '\n';
    }
    else if (const std::string* text = std::any_cast<std::string>(&value))
    {
        std::cout << *text << '\n';
    }
    else
    {
        std::cout << "unsupported type\n";
    }
}

int main()
{
    PrintAny(10);
    PrintAny(3.5);
    PrintAny(std::string{"hello"});
    PrintAny(true);
}
