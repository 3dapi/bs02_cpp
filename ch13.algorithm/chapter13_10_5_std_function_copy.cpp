#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::function<void()> first = [data = std::vector<int>(1000)]
    {
        std::cout << data.size() << '\n';
    };

    std::function<void()> second = first;

    first();
    second();
}
