#include <iostream>
#include <new>

int main()
{
    try
    {
        int* values = new int[100]{};

        std::cout << values[0] << '\n';

        delete[] values;
    }
    catch (const std::bad_alloc& error)
    {
        std::cerr << error.what() << '\n';
    }
}
