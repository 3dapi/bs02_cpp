#include <functional>
#include <iostream>
#include <string>

struct Counter
{
    int value = 0;

    void operator()()
    {
        ++value;
    }
};

template <typename Function>
void ExecuteTwice(Function function)
{
    function();
    function();
}

int main()
{
    Counter counter;
    ExecuteTwice(std::ref(counter));

    const std::string name = "Alice";
    auto nameReference = std::cref(name);

    std::cout << counter.value << '\n';
    std::cout << nameReference.get() << '\n';
}
