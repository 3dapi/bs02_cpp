#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    const int* oldData = values.data();
    const std::size_t oldCapacity = values.capacity();

    values.reserve(oldCapacity + 1);

    std::cout << std::boolalpha
              << (oldData != values.data())
              << '\n';
}
