#include <cstddef>
#include <iostream>

class IntArray
{
public:
    explicit IntArray(std::size_t size)
        : size(size)
    {
    }

	std::size_t GetSize() const
    {
        return size;
    }

private:
    std::size_t size = 0;
};

IntArray SelectArray(bool selectFirst)
{
    IntArray first(10);
    IntArray second(20);

    if (selectFirst)
    {
        return first;
    }
    return second;
}

int main()
{
    IntArray values = SelectArray(false);
    IntArray values2 = values;
    std::cout << values.GetSize() << '\n';
}
