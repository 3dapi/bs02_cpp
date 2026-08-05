#include <iostream>

struct Data
{
    char code;
    int value;
};

int main()
{
    std::cout << alignof(char) << ' ' << alignof(int) << ' ' << alignof(double) << '\n' << sizeof(Data) << '\n';
}
