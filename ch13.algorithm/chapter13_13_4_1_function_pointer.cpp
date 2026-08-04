#include <algorithm>
#include <iostream>
#include <vector>

bool IsEven(int value)
{
    return value % 2 == 0;
}

int main()
{
    using Predicate = bool (*)(int);
    Predicate predicate = IsEven;

    std::vector<int> values{1, 2, 3, 4, 5};
    auto position = std::find_if(values.begin(), values.end(), predicate);

    if (position != values.end())
    {
        std::cout << *position << '\n';
    }
}
