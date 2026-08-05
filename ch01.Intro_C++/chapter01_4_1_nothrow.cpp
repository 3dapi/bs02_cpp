#include <iostream>
#include <new>

void MemoryNewDeleteNothrow()
{
    char* memory = new (std::nothrow) char[100]();
    if (memory != nullptr)
    {
        std::cout << static_cast<int>(memory[0]) << '\n';
        delete[] memory;
    }
}

int main()
{
    MemoryNewDeleteNothrow();
}
