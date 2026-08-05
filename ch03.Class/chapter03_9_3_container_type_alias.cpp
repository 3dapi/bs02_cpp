#include <iostream>
#include <cstddef>

class ItemList
{
public:
    using ValueType = int;
    using SizeType = std::size_t;

    bool Add(ValueType value)
    {
        if (size >= 100)
        {
            return false;
        }

        values[size] = value;
        ++size;

        return true;
    }

    SizeType GetSize() const
    {
        return size;
    }

private:
    ValueType values[100];
    SizeType size = 0;
};

int main()
{
    ItemList items;

    items.Add(1001);
    items.Add(1002);

    std::cout << items.GetSize() << '\n';
}
