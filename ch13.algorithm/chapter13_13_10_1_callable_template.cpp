#include <iostream>

template <typename Callback>
void Execute(int value, Callback callback)
{
    callback(value);
}

int main()
{
    Execute(10, [](int value)
    {
        std::cout << value << '\n';
    });
}
