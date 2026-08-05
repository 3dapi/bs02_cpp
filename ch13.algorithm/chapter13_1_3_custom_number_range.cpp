#include <iostream>

class NumberRange
{
public:
    NumberRange(int* first, int* last)
        : first(first), last(last)
    {
    }

    int* begin()
    {
        return first;
    }

    int* end()
    {
        return last;
    }

private:
    int* first;
    int* last;
};

int main()
{
    int values[]{10, 20, 30};
    NumberRange range{values, values + 3};

    for (int value : range)
    {
        std::cout << value << ' ';
    }
}
