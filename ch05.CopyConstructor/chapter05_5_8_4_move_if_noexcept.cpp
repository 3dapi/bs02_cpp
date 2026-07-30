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

    Trace(Trace&&)
    {
        std::cout << "move\n";
    }
};

int main()
{
    Trace source;
    Trace target(std::move_if_noexcept(source));

    static_cast<void>(target);
}
