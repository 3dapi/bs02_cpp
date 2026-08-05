#include <iostream>

int main()
{
    int* first = new int;
    int* second = new int(100);
    int* third = new int{};

    *first = 10;

    std::cout << *first << '\n';
    std::cout << *second << '\n';
    std::cout << *third << '\n';

    delete first;
    delete second;
    delete third;
}
