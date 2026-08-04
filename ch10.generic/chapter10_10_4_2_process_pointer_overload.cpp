#include <iostream>

template <typename T>
void Process(const T& value)
{
    std::cout << "value: " << value << '\n';
}

template <typename T>
void Process(T* value)
{
    if (value != nullptr)
    {
        std::cout << "pointer: " << *value << '\n';
    }
}

int main()
{
    int number = 10;

    Process(number);
    Process(&number);
}
