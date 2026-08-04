#include <functional>
#include <iostream>

int AddOne(int value)
{
    return value + 1;
}

int main()
{
    std::reference_wrapper<int(int)> function = std::ref(AddOne);
    int result = function(10);

    std::cout << result << '\n';
}
