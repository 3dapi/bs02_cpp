#include <iostream>

int Add(int first, int second)
{
    return first + second;
}

int main()
{
    int result = Add(10, 20);
    std::cout << result << '\n';
}
