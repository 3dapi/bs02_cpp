#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    auto getFirst = [&values]() -> int&
    {
        return values.front();
    };

    getFirst() = 100;
    std::cout << values.front() << '\n';
}
