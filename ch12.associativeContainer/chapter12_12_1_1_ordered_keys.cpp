#include <iostream>
#include <set>

int main()
{
    std::set<int> values{30, 10, 20};

    for (int value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
