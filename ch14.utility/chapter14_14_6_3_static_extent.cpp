#include <array>
#include <iostream>
#include <span>

void NormalizeColor(std::span<float, 4> color)
{
    for (float& component : color)
    {
        if (component < 0.0f)
        {
            component = 0.0f;
        }
        else if (component > 1.0f)
        {
            component = 1.0f;
        }
    }
}

int main()
{
    std::array<float, 4> color{1.2f, 0.5f, -0.25f, 1.0f};
    std::span<float, 4> colorView{color};

    static_assert(colorView.extent == 4);

    NormalizeColor(colorView);

    for (float component : color)
    {
        std::cout << component << ' ';
    }
}
