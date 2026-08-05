#include <iostream>

int main()
{
    int count = 0;

    auto increment = [count]() mutable
    {
        return ++count;
    };

    std::cout << increment() << '\n';
    std::cout << increment() << '\n';
    std::cout << count << '\n';
}
