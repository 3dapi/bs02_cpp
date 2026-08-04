#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values;
    const int* previousData = values.data();

    for (int value = 0; value < 20; ++value)
    {
        values.push_back(value);

        if (values.data() != previousData)
        {
            std::cout << "reallocated: size=" << values.size()
                      << " capacity=" << values.capacity()
                      << '\n';
            previousData = values.data();
        }
    }
}
