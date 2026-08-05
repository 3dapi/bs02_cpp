#include <iostream>

int main()
{
    int* first = new int(100);
    int* second = first;

    std::cout << *second << '\n';

    delete first;

    first = nullptr;
    second = nullptr;

    std::cout << std::boolalpha;
    std::cout << (first == nullptr) << '\n';
    std::cout << (second == nullptr) << '\n';
}
