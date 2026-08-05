#include <cstddef>
#include <iostream>
#include <optional>
#include <vector>

std::optional<std::size_t> FindIndex(
    const std::vector<int>& values,
    int target)
{
    for (std::size_t index = 0; index < values.size(); ++index)
    {
        if (values[index] == target)
        {
            return index;
        }
    }

    return std::nullopt;
}

int main()
{
    std::vector<int> values{10, 20, 30};
    std::optional<std::size_t> index = FindIndex(values, 30);

    if (index)
    {
        std::cout << "index: " << *index << '\n';
    }
    else
    {
        std::cout << "not found\n";
    }
}
