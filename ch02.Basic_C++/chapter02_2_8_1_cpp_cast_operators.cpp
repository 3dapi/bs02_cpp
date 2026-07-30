#include <cstdint>
#include <iostream>

int main()
{
    double speed{ 10.5 };
    int value{ static_cast<int>(speed) };
    int number{ 10 };
    int* pointer{ &number };
    std::uintptr_t address{ reinterpret_cast<std::uintptr_t>(pointer) };
    std::cout << value << ' ' << address << '\n';
}
