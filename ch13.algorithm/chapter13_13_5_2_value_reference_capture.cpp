#include <iostream>

int main()
{
    int limit = 20;

    auto predicate = [limit](int value)
    {
        return value > limit;
    };

    limit = 100;
    std::cout << std::boolalpha << predicate(50) << '\n';

    int total = 0;

    auto add = [&total](int value)
    {
        total += value;
    };

    add(10);
    add(20);
    std::cout << total << '\n';
}
