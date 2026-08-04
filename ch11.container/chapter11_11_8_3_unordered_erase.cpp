#include <iostream>
#include <utility>
#include <vector>

void UnorderedErase(std::vector<int>& values, std::size_t index)
{
    if (index >= values.size())
    {
        return;
    }

    values[index] = std::move(values.back());
    values.pop_back();
}

int main()
{
    std::vector<int> values{10, 20, 30, 40};
    UnorderedErase(values, 1);

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
