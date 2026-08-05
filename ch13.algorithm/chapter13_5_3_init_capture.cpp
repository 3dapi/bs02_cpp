#include <iostream>

int main()
{
    int base = 10;

    auto add = [offset = base * 2](int value)
    {
        return value + offset;
    };

    std::cout << add(5) << '\n';
}
