#include <iostream>

int main()
{
    auto add = [](int left, int right)
    {
        return left + right;
    };

    std::cout << add(10, 20) << '\n';
}
