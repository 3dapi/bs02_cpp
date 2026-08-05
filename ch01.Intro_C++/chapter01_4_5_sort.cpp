#include <algorithm>
#include <functional>
#include <iostream>
#include <span>
using std::cout;
using std::span;

int main()
{
    int values[] = { 1, 9, 2, 3, 5, 7, 4, 17 };

    cout << "오름차순 정렬\n";

    span<int> range(values);
    std::sort(range.begin(), range.end());

    for (int value : values)
        cout << value << "  ";

    cout << "\n\n";
    cout << "내림차순 정렬\n";

    std::sort(range.begin(), range.end(), std::greater<int>());

    for (int value : values)
        cout << value << "  ";

    cout << '\n';
}
