#include <iostream>

class Length
{
public:
    Length(int value)
    {
        if (value >= 0)
        {
            this->value = value;
        }
        else
        {
            this->value = 0;
        }
    }

    int Value() const
    {
        return value;
    }

private:
    int value;
};

void PrintLength(const Length& length)
{
    std::cout << length.Value() << '\n';
}

int main()
{
    Length first(100);
    Length second = 200;

    PrintLength(first);
    PrintLength(second);
    PrintLength(300);
}
