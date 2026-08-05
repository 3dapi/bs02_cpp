#include <iostream>

constinit int objectCount = 0;
constinit const int maximumCount = 100;

void IncreaseCount()
{
    ++objectCount;
}

int main()
{
    IncreaseCount();

    std::cout << objectCount << '\n';
    std::cout << maximumCount << '\n';
}
