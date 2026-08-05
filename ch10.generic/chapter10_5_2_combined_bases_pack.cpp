#include <iostream>
#include <utility>

class FirstBase
{
public:
    explicit FirstBase(int value)
        : value(value)
    {
    }

    int GetFirst() const
    {
        return value;
    }

private:
    int value;
};

class SecondBase
{
public:
    explicit SecondBase(double value)
        : value(value)
    {
    }

    double GetSecond() const
    {
        return value;
    }

private:
    double value;
};

template <typename... Bases>
class Combined : public Bases...
{
public:
    explicit Combined(Bases... bases)
        : Bases(std::move(bases))...
    {
    }
};

int main()
{
    Combined<FirstBase, SecondBase> combined(
        FirstBase(10),
        SecondBase(3.5));

    std::cout << combined.GetFirst() << '\n';
    std::cout << combined.GetSecond() << '\n';
}
