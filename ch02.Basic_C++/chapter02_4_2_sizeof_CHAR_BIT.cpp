#include <climits>
#include <iostream>

int main()
{
    int value = 10;
    std::cout << sizeof(value) << ' ' << CHAR_BIT << '\n';
    std::cout << sizeof(++value) << ' ' << value << '\n';
}
