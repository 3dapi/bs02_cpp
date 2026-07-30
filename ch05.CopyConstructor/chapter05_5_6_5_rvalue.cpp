#include <iostream>
#include <utility>

void Process(const int& value)
{
    std::cout << "const lvalue reference: " << value << '\n';
}

void Process(int&& value)
{
    std::cout << "rvalue reference: " << value << '\n';
}

int main()
{
    int first = 10;
    int second = 20;

    Process(first + second);
    Process(std::move(first));
}
