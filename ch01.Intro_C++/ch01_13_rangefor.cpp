#include <iostream>
#include <vector>

using std::cout;

std::vector<int> GetValues()
{
    std::vector<int> values = {11, 22, 33, 44, 55};
    return values;
}

int main()
{
    cout << "C++11 범위 기반 for문\n";
    int values[] = {10, 20, 30, 40, 50};
    for(int value : values)
    {
        cout << value << ' ';
    }

    cout << "\n\n";
    cout << "C++20 초기화 구문이 있는 범위 기반 for문\n";
    for(std::vector<int> dynamicValues = GetValues();
         int value : dynamicValues)
    {
        cout << value << ' ';
    }
    cout << '\n';
}
