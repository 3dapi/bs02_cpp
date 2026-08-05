#include <cstddef>
#include <iostream>
#include <stdexcept>

enum class OverflowPolicy
{
    Ignore,
    Throw
};

template <typename T,
          std::size_t Size,
          OverflowPolicy Policy = OverflowPolicy::Throw>
class LimitedBuffer
{
public:
    void Push(const T& value)
    {
        if (count == Size)
        {
            if constexpr (Policy == OverflowPolicy::Throw)
            {
                throw std::overflow_error("LimitedBuffer is full");
            }
            else
            {
                return;
            }
        }

        values[count++] = value;
    }

    std::size_t GetCount() const
    {
        return count;
    }

private:
    T values[Size]{};
    std::size_t count = 0;
};

int main()
{
    LimitedBuffer<int, 2, OverflowPolicy::Ignore> buffer;

    buffer.Push(10);
    buffer.Push(20);
    buffer.Push(30);

    std::cout << buffer.GetCount() << '\n';
}
