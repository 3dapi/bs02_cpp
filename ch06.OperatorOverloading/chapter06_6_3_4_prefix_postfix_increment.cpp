#include <iostream>

class Counter
{
public:
    explicit Counter(int value = 0)
        : value(value)
    {
    }

    Counter& operator++()
    {
        ++value;
        return *this;
    }

    Counter operator++(int)
    {
        Counter previous = *this;
        ++(*this);
        return previous;
    }

public:
    int value = 0;
};

int main()
{
    Counter counter(10);

    Counter prefix = ++counter;
    Counter postfix = counter++;

    std::cout << prefix.value << '\n';
    std::cout << postfix.value << '\n';
    std::cout << counter.value << '\n';
}
