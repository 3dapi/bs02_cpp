#include <cstddef>
#include <iostream>

struct Data
{
    char code;
    int value;
};

int main()
{
    std::cout << sizeof(char) + sizeof(int) << '\n';
    std::cout << sizeof(Data) << '\n';
    std::cout << alignof(Data) << '\n';
}
