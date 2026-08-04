#include <iostream>
#include <optional>

class Percentage
{
public:
    static std::optional<Percentage> Create(int value)
    {
        if (value < 0 || value > 100)
        {
            return std::nullopt;
        }

        return Percentage{value};
    }

    int Get() const
    {
        return value;
    }

private:
    explicit Percentage(int value)
        : value(value)
    {
    }

    int value;
};

int main()
{
    std::optional<Percentage> valid = Percentage::Create(75);
    std::optional<Percentage> invalid = Percentage::Create(120);

    if (valid)
    {
        std::cout << valid->Get() << '\n';
    }

    std::cout << std::boolalpha
              << invalid.has_value()
              << '\n';
}
