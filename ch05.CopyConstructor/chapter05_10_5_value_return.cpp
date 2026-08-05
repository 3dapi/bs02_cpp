#include <cstddef>
#include <iostream>
#include <vector>

std::vector<int> CreateValues(std::size_t size)
{
    return std::vector<int>(size, 0);
}

int main()
{
    std::vector<int> values = CreateValues(1000);
    std::cout << values.size() << '\n';
}
