#include <any>
#include <iostream>
#include <string>

int main()
{
    std::any value = std::string{"hello"};

    std::string copied = std::any_cast<std::string>(value);
    std::string& reference = std::any_cast<std::string&>(value);
    reference += " world";

    std::cout << copied << '\n';
    std::cout << reference << '\n';

    if (std::string* text = std::any_cast<std::string>(&value))
    {
        std::cout << *text << '\n';
    }

    if (std::any_cast<int>(&value) == nullptr)
    {
        std::cout << "type mismatch\n";
    }
}
