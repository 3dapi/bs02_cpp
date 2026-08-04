#include <iostream>
#include <vector>

int main()
{
    auto getSize = []<typename T>(const std::vector<T>& values)
    {
        return values.size();
    };

    auto maximum = []<typename T>(T left, T right)
    {
        return left < right ? right : left;
    };

    std::vector<int> values{10, 20, 30};
    std::cout << getSize(values) << '\n';
    std::cout << maximum(10, 20) << '\n';
}
