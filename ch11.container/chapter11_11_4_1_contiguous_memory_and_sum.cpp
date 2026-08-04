#include <iostream>
#include <vector>

long long Sum(const std::vector<int>& values)
{
    long long total = 0;

    for (int value : values)
    {
        total += value;
    }

    return total;
}

int main()
{
    std::vector<int> values{10, 20, 30};

    int* first = &values[0];
    int* data = values.data();

    std::cout << std::boolalpha
              << (first == data) << ' '
              << Sum(values) << '\n';
}
