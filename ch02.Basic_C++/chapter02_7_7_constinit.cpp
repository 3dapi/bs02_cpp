#include <iostream>

constinit int globalCount = 10;

int main()
{
    globalCount = 20;
    std::cout << globalCount << '\n';
}
