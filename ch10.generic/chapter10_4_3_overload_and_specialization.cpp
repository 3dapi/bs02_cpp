#include <iostream>
#include <string>

template <typename T>
void Serialize(const T& value)
{
    std::cout << value;
}

template <>
void Serialize<std::string>(const std::string& value)
{
    std::cout << '"' << value << '"';
}

template <typename T>
void Write(const T& value)
{
    std::cout << value;
}

void Write(const std::string& value)
{
    std::cout << '"' << value << '"';
}

int main()
{
    const std::string text = "Knight";

    Serialize(text);
    std::cout << '\n';

    Write(text);
    std::cout << '\n';
}
