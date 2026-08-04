#include <iostream>
#include <string>
#include <utility>

void Use(const std::string& value)
{
    std::cout << "copy-like use: " << value << '\n';
}

void Use(std::string&& value)
{
    std::cout << "move-like use: " << value << '\n';
}

template <typename T>
void RelayWrong(T&& value)
{
    Use(value);
}

template <typename T>
void RelayCorrect(T&& value)
{
    Use(std::forward<T>(value));
}

int main()
{
    std::string name = "Knight";

    RelayWrong(name);
    RelayWrong(std::string("Mage"));

    RelayCorrect(name);
    RelayCorrect(std::string("Mage"));
}
