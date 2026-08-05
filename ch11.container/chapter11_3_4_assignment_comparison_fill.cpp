#include <array>
#include <iostream>

int main()
{
    std::array<int, 3> source{10, 20, 30};
    std::array<int, 3> destination{};
    destination = source;

    std::array<int, 3> left{1, 2, 3};
    std::array<int, 3> right{1, 2, 4};

    std::array<int, 8> cells{};
    cells.fill(-1);

    std::cout << std::boolalpha
              << (destination == source) << ' '
              << (left < right) << ' '
              << cells.front() << '\n';
}
