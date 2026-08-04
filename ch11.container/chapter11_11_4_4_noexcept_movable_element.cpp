#include <iostream>
#include <vector>

class Data
{
public:
    explicit Data(int value)
        : value(value)
    {
    }

    Data(const Data& other)
        : value(other.value)
    {
        std::cout << "copy\n";
    }

    Data(Data&& other) noexcept
        : value(other.value)
    {
        std::cout << "move\n";
    }

    int GetValue() const
    {
        return value;
    }

private:
    int value;
};

int main()
{
    std::vector<Data> values;
    values.reserve(1);
    values.emplace_back(10);
    values.emplace_back(20);

    std::cout << values.front().GetValue() << '\n';
}
