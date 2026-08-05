#include <algorithm>
#include <iostream>
#include <vector>

bool IsEven(int value)
{
    return value % 2 == 0;
}

int main()
{
    // 함수 포인터.
    using Predicate = bool (*)(int);
    Predicate predicate = IsEven;
    std::cout << std::boolalpha
        << predicate(10) << '\n';

    std::vector<int> values{1, 2, 3, 4, 5};

    // 표준 알고리즘에 함수 포인터 전달.
    auto position = std::find_if(values.begin(), values.end(), predicate);
    if(position != values.end())
    {
        std::cout << *position << '\n';
    }
}
