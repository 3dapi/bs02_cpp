#include <initializer_list>
#include <iostream>

class NumberSet
{
public:
    NumberSet(int count, int value)
    {
        std::cout << "NumberSet(int, int): "
                  << count << ", " << value << '\n';
    }

    NumberSet(std::initializer_list<int> values)
    {
        std::cout << "NumberSet(initializer_list): "
                  << values.size() << '\n';
    }
};

int main()
{
    NumberSet first(10, 20);
    NumberSet second{10, 20};
}
