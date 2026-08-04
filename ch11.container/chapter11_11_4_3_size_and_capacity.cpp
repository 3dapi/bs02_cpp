#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values;

    for (int value = 1; value <= 8; ++value)
    {
        values.push_back(value * 10);
        std::cout << "size=" << values.size()
                  << " capacity=" << values.capacity()
                  << '\n';
    }
}
