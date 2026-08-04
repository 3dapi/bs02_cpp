#include <iostream>
#include <span>

void PrintValues(std::span<const int> values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int values[]{10, 20, 30};
    std::span<int> view{values};

    std::cout << view.size() << ' '
              << std::boolalpha << view.empty() << '\n';

    view.front() = 100;
    view.back() = 300;
    PrintValues(view);
}
