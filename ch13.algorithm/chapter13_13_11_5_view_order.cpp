#include <iostream>
#include <ranges>
#include <vector>

struct IsEven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};

    auto first = values
        | std::views::filter(IsEven{})
        | std::views::take(3);

    auto second = values
        | std::views::take(3)
        | std::views::filter(IsEven{});

    for (int value : first)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    for (int value : second)
    {
        std::cout << value << ' ';
    }
}
