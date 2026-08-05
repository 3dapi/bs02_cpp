#include <iostream>

class RenderOption
{
public:
    RenderOption& SetResolution(int width, int height)
    {
        if (width > 0 && height > 0)
        {
            this->width = width;
            this->height = height;
        }

        return *this;
    }

    RenderOption& SetFullScreen(bool enabled)
    {
        fullScreen = enabled;
        return *this;
    }

    void Print() const
    {
        std::cout << width << " x " << height << '\n';
        std::cout << std::boolalpha << fullScreen << '\n';
    }

private:
    int width = 1280, height = 720;
    bool fullScreen = false;
};

int main()
{
    RenderOption option;
    RenderOption& result = option.SetResolution(1920, 1080);

    result.SetFullScreen(true);
    option.Print();
}
