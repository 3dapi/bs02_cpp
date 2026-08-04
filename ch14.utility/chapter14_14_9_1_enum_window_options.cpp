#include <iostream>


enum class BorderMode
{
    Hidden,
    Visible
};

enum class ResizeMode
{
    Fixed,
    Resizable
};

void OpenWindow(BorderMode border, ResizeMode resize)
{
    std::cout << (border == BorderMode::Visible ? "border" : "no border")
              << ' '
              << (resize == ResizeMode::Resizable ? "resizable" : "fixed")
              << '\n';
}

int main()
{
    OpenWindow(BorderMode::Visible, ResizeMode::Fixed);
}
