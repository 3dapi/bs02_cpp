#include <iostream>
#include <string>
#include <string_view>

void PrintName(std::string_view name)
{
    std::cout << name << '\n';
}

int main()
{
    PrintName("Alice");

    std::string name = "Bob";
    PrintName(name);

    std::string_view text = "[message]";
    text.remove_prefix(1);
    text.remove_suffix(1);

    std::cout << text << '\n';
}
