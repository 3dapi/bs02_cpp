#include <iostream>

int main()
{
    const int original{ 10 };
    auto copiedValue = original;
    int value{ 10 };
    auto&reference = value;
    const auto&constReference = value;
    reference = 20;
    std::cout << copiedValue << ' ' << value << ' ' << constReference << '\n';
}
