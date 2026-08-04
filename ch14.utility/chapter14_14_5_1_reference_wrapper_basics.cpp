#include <functional>
#include <iostream>

int main()
{
    int value = 10;
    std::reference_wrapper<int> reference = std::ref(value);

    reference.get() = 20;

    int& alias = reference;
    alias = 30;

    auto copied = reference;
    copied.get() = 40;

    std::cout << value << '\n';
}
