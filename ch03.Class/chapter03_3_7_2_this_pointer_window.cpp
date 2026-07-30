#include <iostream>

class Window
{
public:
    void SetSize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    void Print() const
    {
        std::cout << width << " x " << height << '\n';
    }

private:
    int width = 800, height = 600;
};

int main()
{
    Window first;
    Window second;

    first.SetSize(1280, 720);
    second.SetSize(1920, 1080);

    first.Print();
    second.Print();
}
