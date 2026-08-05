#include <iostream>

int main()
{
    int values[5]{1, 2};

    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
