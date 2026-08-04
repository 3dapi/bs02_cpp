#include <iostream>

int main()
{
    int values[]{10, 20, 30};

    int* first = values;
    int* last = values + 3;

    for (int* pointer = first; pointer != last; ++pointer)
    {
        std::cout << *pointer << ' ';
    }
}
