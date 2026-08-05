#include <cstddef>
#include <iostream>
#include <utility>

class IntArray
{
public:
    explicit IntArray(std::size_t size)
        : size(size),
          data(size > 0 ? new int[size]{} : nullptr)
    {
    }

    ~IntArray()
    {
        delete[] data;
    }

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    IntArray(IntArray&& other) noexcept
        : size(other.size),
          data(other.data)
    {
        other.size = 0;
        other.data = nullptr;
    }

    std::size_t GetSize() const
    {
        return size;
    }

private:
    std::size_t size = 0;
    int* data = nullptr;
};

int main()
{
    IntArray source(10);
    IntArray target(std::move(source));

    std::cout << target.GetSize() << '\n';
}
