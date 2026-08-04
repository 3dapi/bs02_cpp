#include <iostream>
#include <new>

int main()
{
    int* values = new (std::nothrow) int[100]{};

    if (values == nullptr)
    {
        std::cerr << "메모리 할당 실패\n";
        return 1;
    }

    std::cout << values[0] << '\n';

    delete[] values;
}
