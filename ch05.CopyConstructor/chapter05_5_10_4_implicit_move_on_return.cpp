#include <iostream>

class Trace
{
public:
    explicit Trace(int id)
        : id(id)
    {
    }

    Trace(const Trace& other)
        : id(other.id)
    {
        std::cout << "copy\n";
    }

    Trace(Trace&& other) noexcept
        : id(other.id)
    {
        std::cout << "move\n";
    }

    int GetId() const
    {
        return id;
    }

private:
    int id = 0;
};

Trace Select(bool first)
{
    Trace left(1);
    Trace right(2);

    if (first)
    {
        return left;
    }

    return right;
}

int main()
{
    Trace result = Select(true);
    std::cout << result.GetId() << '\n';
}
