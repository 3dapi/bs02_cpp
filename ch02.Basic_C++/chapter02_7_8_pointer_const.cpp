#include <iostream>

int main()
{
    int first{ 10 };
    int second{ 20 };
    const int* pointerToConst{ &first };
    int* const constPointer{ &first };
    const int* const constPointerToConst{ &first };
    pointerToConst = &second;
    *constPointer = 30;
    std::cout << *pointerToConst << ' ' << *constPointer << ' ' << *constPointerToConst << '\n';
}
