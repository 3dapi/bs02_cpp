#include <iostream>
#include <algorithm>
#include <span>
using std::span;
using std::cout;

int main()
{
    int values[] = {1, 9, 2, 3, 5, 7, 4, 17};
    cout <<"오름 차순 정렬" << '\n';
    if(false)
    {
        std::sort(values, values + 8);
    }
    else
    {
        span<int> range(values);
        std::sort(range.begin(), range.end());
    }
    for(int v : values)
        cout << v << "  ";
    cout << "\n\n";

    cout <<"내림 차순 정렬" << '\n';
    if(false)
    {
        std::sort(values, values + 8, std::greater<int>());
    }
    else
    {
        span<int> range(values);
        std::sort(range.begin(), range.end(), std::greater<>());
    }
    for(int v : values)
        cout << v << "  ";
    cout << '\n';
}
