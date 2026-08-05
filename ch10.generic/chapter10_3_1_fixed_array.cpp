#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T, std::size_t Size>
class FixedArray
{
public:
    T& At(std::size_t index)
    {
        if (index >= Size)
        {
            throw std::out_of_range("FixedArray index out of range");
        }

        return values[index];
    }

    const T& At(std::size_t index) const
    {
        if (index >= Size)
        {
            throw std::out_of_range("FixedArray index out of range");
        }

        return values[index];
    }

    constexpr std::size_t SizeValue() const noexcept
    {
        return Size;
    }

    void Fill(const T& value)
    {
        for (std::size_t index = 0; index < Size; ++index)
        {
            values[index] = value;
        }
    }

private:
    static_assert(Size > 0, "FixedArray size must be positive");
    T values[Size]{};
};

int main()
{
    FixedArray<int, 4> scores;
    FixedArray<double, 8> weights;

    scores.Fill(10);
    weights.Fill(2.5);

    std::cout << scores.At(0) << '\n';
    std::cout << weights.At(7) << '\n';
    std::cout << scores.SizeValue() << '\n';
}
