#include <iostream>
#include <utility>

class Trace
{
public:
    Trace() = default;

    Trace(const Trace&)
    {
        std::cout << "copy\n";
    }

    Trace(Trace&&) noexcept
    {
        std::cout << "move\n";
    }
};

int main()
{
    Trace source;
    Trace first(source);
    Trace second(std::move(source));

    static_cast<void>(first);
    static_cast<void>(second);
}
