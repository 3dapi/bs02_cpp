#include <iostream>

class AddOffset
{
public:
    explicit AddOffset(int offset)
        : offset(offset)
    {
    }

    int operator()(int value) const
    {
        return value + offset;
    }

private:
    int offset;
};

int main()
{
    int offset = 10;

    auto lambda = [offset](int value)
    {
        return value + offset;
    };

    AddOffset object(offset);

    std::cout << lambda(5) << '\n';
    std::cout << object(5) << '\n';
}
