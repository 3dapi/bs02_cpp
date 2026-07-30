#include <iostream>

class RenderOption
{
public:
    RenderOption& SetFullScreenByReference(bool enabled)
    {
        fullScreen = enabled;
        return *this;
    }

    RenderOption SetFullScreenByValue(bool enabled)
    {
        fullScreen = enabled;
        return *this;
    }

    bool IsFullScreen() const
    {
        return fullScreen;
    }

private:
    bool fullScreen = false;
};

int main()
{
    RenderOption option;
    RenderOption& reference = option.SetFullScreenByReference(true);
    RenderOption copy = option.SetFullScreenByValue(false);

    std::cout << std::boolalpha;
    std::cout << option.IsFullScreen() << '\n';
    std::cout << reference.IsFullScreen() << '\n';
    std::cout << copy.IsFullScreen() << '\n';
}
