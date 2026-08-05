#include <iostream>
#include <utility>

class IntArray
{
};

void Process(const IntArray&)
{
    std::cout << "const reference\n";
}

void Process(IntArray&&)
{
    std::cout << "rvalue reference\n";
}

int main()
{
    IntArray values;

    Process(values);
    Process(std::move(values));
}
