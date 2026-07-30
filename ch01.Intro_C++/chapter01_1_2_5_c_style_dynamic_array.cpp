#include <cstdlib>
#include <iostream>

void ProcessData()
{
    int* values = static_cast<int*>(std::malloc(sizeof(int) * 100));
    if (values == nullptr)
    {
        return;
    }

    values[0] = 10;
    std::cout << values[0] << '\n';

    std::free(values);
}

int main()
{
    ProcessData();
}
