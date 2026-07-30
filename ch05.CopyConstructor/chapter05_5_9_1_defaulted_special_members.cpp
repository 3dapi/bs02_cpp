#include <iostream>
#include <string>
#include <utility>

class Data
{
public:
    Data() = default;
    ~Data() = default;

    Data(const Data&) = default;
    Data& operator=(const Data&) = default;
    Data(Data&&) noexcept = default;
    Data& operator=(Data&&) noexcept = default;

    void SetValue(std::string value)
    {
        this->value = std::move(value);
    }

    const std::string& GetValue() const
    {
        return value;
    }

private:
    std::string value;
};

int main()
{
    Data first;
    first.SetValue("Player");

    Data second = first;
    Data third = std::move(first);

    std::cout << second.GetValue() << '\n';
    std::cout << third.GetValue() << '\n';
}
