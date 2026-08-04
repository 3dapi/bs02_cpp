#include <iostream>

class Counter
{
public:
    explicit Counter(int value)
        : value(value)
    {
    }

    void SetValue(int value)
    {
        this->value = value;
    }

    auto MakeReferenceReader()
    {
        return [this]
        {
            return value;
        };
    }

    auto MakeCopyReader() const
    {
        return [*this]
        {
            return value;
        };
    }

private:
    int value;
};

int main()
{
    Counter counter(10);
    auto referenceReader = counter.MakeReferenceReader();
    auto copyReader = counter.MakeCopyReader();

    counter.SetValue(20);

    std::cout << referenceReader() << '\n';
    std::cout << copyReader() << '\n';
}
