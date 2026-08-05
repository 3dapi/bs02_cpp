#include <iostream>

class RenderOption
{
public:
    int GetWidth() const
    {
        return width;
    }

private:
    int width = 1280;
};

int main()
{
    const RenderOption option;

    std::cout << option.GetWidth() << '\n';
}
