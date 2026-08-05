#include <array>
#include <iostream>
#include <span>

void Print(std::span<const int> values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::array<int, 6> values{10, 20, 30, 40, 50, 60};
    std::span<int> all{values};

    auto firstThree = all.first<3>();
    auto lastTwo = all.last<2>();
    auto middle = all.subspan(1, 3);

    middle[0] = 200;

    Print(firstThree);
    Print(lastTwo);
    Print(middle);
}
