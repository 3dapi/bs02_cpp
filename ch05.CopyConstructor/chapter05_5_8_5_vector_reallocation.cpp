#include <iostream>
#include <vector>

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
    std::vector<Trace> values;
    values.reserve(1);

    values.emplace_back();
    values.emplace_back();

    std::cout << values.size() << '\n';
}
