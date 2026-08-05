#include <cstddef>
#include <iostream>

template <typename T, std::size_t Size>
class StaticBuffer
{
public:
    constexpr std::size_t GetCapacity() const noexcept
    {
        return Size;
    }

    T& operator[](std::size_t index)
    {
        return values[index];
    }

    const T& operator[](std::size_t index) const
    {
        return values[index];
    }

private:
    T values[Size]{};
};

int main()
{
    constexpr std::size_t PlayerCount = 4;
    StaticBuffer<int, PlayerCount> scores;

    scores[0] = 100;

    static_assert(
        StaticBuffer<int, 32>{}.GetCapacity() == 32);

    std::cout << scores[0] << '\n';
    std::cout << scores.GetCapacity() << '\n';
}
