#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 15, 20, 25};

    int count = std::count_if(
        values.begin(),
        values.end(),
        [](int value)
        {
            return value % 2 == 0;
        });

    std::cout << count << '\n';
}
