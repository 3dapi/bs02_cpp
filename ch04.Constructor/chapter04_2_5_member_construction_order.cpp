#include <iostream>

class Border
{
public:
    Border()
    {
        std::cout << "Border 생성\n";
    }

    ~Border()
    {
        std::cout << "Border 소멸\n";
    }
};

class Window
{
public:
    Window()
    {
        std::cout << "Window 생성\n";
    }

    ~Window()
    {
        std::cout << "Window 소멸\n";
    }

private:
    Border border;
};

int main()
{
    Window window;
}
