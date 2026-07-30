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
    const Trace source;
    Trace target(std::move(source));

    static_cast<void>(target);
}
