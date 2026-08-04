#include <iostream>


auto MakeAdder(int offset)
{
    return [offset](int value)
    {
        return value + offset;
    };
}

int main()
{
    auto addTen = MakeAdder(10);
    std::cout << addTen(5) << '\n';
}
