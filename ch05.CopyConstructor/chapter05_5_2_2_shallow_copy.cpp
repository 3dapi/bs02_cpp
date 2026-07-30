#include <cstddef>
#include <iostream>

class ArrayView
{
public:
    ArrayView(int* data, std::size_t size)
        : data(data), size(size)
    {
    }

    void Set(std::size_t index, int value)
    {
        if (index < size)
        {
            data[index] = value;
        }
    }

    int Get(std::size_t index) const
    {
        return index < size ? data[index] : 0;
    }

private:
    int* data = nullptr;
    std::size_t size = 0;
};

int main()
{
    int values[3]{10, 20, 30};
    ArrayView first(values, 3);
    ArrayView second = first;

    second.Set(0, 100);

    std::cout << first.Get(0) << '\n';
}
