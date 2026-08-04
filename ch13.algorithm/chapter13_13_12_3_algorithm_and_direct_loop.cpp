#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, -5, 20, -1, 30};

    bool hasNegative = std::any_of(
        values.begin(),
        values.end(),
        [](int value)
        {
            return value < 0;
        });

    int positiveCount = 0;
    int negativeCount = 0;
    long long total = 0;

    for (int value : values)
    {
        total += value;

        if (value >= 0)
        {
            ++positiveCount;
        }
        else
        {
            ++negativeCount;
        }
    }

    std::cout << std::boolalpha << hasNegative << '\n';
    std::cout << positiveCount << ' '
              << negativeCount << ' '
              << total << '\n';
}
