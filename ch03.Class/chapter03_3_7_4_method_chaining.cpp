#include <iostream>

class RenderOption
{
public:
    RenderOption& SetResolution(int width, int height)
    {
        this->width = width;
        this->height = height;
        return *this;
    }

    RenderOption& SetFullScreen(bool enabled)
    {
        fullScreen = enabled;
        return *this;
    }

    RenderOption& SetVSync(bool enabled)
    {
        vSync = enabled;
        return *this;
    }

    void Print() const
    {
        std::cout << width << " x " << height << '\n';
        std::cout << std::boolalpha
                  << fullScreen << ", "
                  << vSync << '\n';
    }

private:
    int width = 1280, height = 720;
    bool fullScreen = false;
    bool vSync = true;
};

int main()
{
    RenderOption option;

    option.SetResolution(1920, 1080)
          .SetFullScreen(true)
          .SetVSync(false);

    option.Print();
}
