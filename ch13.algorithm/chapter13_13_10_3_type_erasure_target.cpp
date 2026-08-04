#include <functional>
#include <iostream>

struct Printer
{
    void operator()(int value) const
    {
        std::cout << value << '\n';
    }
};

int main()
{
    std::function<void(int)> callback = Printer{};

    if (Printer* printer = callback.target<Printer>())
    {
        (*printer)(10);
    }
}
