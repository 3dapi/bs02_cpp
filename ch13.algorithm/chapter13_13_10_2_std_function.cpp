#include <functional>
#include <iostream>

void PrintValue(int value)
{
    std::cout << "function: " << value << '\n';
}

struct Printer
{
    void operator()(int value) const
    {
        std::cout << "object: " << value << '\n';
    }
};

int main()
{
    std::function<void(int)> callback = PrintValue;
    callback(10);

    callback = Printer{};
    callback(20);

    int offset = 100;
    callback = [offset](int value)
    {
        std::cout << "lambda: " << value + offset << '\n';
    };

    callback(30);
}
