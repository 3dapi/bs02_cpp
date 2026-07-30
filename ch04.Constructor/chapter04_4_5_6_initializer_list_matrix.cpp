#include <initializer_list>
#include <iostream>

class Matrix2x2
{
public:
    Matrix2x2(std::initializer_list<int> values)
    {
        int index = 0;

        for (int value : values)
        {
            if (index >= 4)
            {
                break;
            }

            elements[index] = value;
            ++index;
        }

        while (index < 4)
        {
            elements[index] = 0;
            ++index;
        }
    }

    void Print() const
    {
        for (int value : elements)
        {
            std::cout << value << ' ';
        }

        std::cout << '\n';
    }

private:
    int elements[4];
};

int main()
{
    Matrix2x2 first{1, 2, 3, 4};
    Matrix2x2 second{1, 2};

    first.Print();
    second.Print();
}
