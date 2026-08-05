#include <iostream>

void MemoryNewDelete()
{
    char* memory = new char[100]();

    std::cout << static_cast<int>(memory[0]) << '\n';

    delete[] memory;
}

int main()
{
    MemoryNewDelete();
}
