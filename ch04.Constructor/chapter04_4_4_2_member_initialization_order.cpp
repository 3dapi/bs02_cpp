#include <iostream>

class Size
{
public:
    Size(int width)
        : width(width), area(width * width)
    {
    }

    void Print() const
    {
        std::cout << width << ", " << area << '\n';
    }

private:
    int width;
    int area;
};

int main()
{
    Size size(10);
    size.Print();
}
