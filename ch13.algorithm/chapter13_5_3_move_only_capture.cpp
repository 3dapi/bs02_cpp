#include <iostream>
#include <memory>
#include <utility>

int main()
{
    auto value = std::make_unique<int>(100);

    auto print = [stored = std::move(value)]
    {
        std::cout << *stored << '\n';
    };

    print();
    std::cout << std::boolalpha << (value == nullptr) << '\n';
}
