#include <iostream>

int main()
{
    int value = 100;
    void* memory = &value;
    int* pointer = static_cast<int*>(memory);

    std::cout << *pointer << '\n';
}
