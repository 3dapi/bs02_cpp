#include <iostream>

class ShapeId
{
public:
    ShapeId(int id)
        : id(id)
    {
    }

    int Value() const
    {
        return id;
    }

private:
    const int id;
};

int main()
{
    ShapeId id(1001);
    std::cout << id.Value() << '\n';
}
