#include <functional>
#include <iostream>
#include <utility>

class Button
{
public:
    using ClickHandler = std::function<void()>;

    void SetOnClick(ClickHandler handler)
    {
        onClick = std::move(handler);
    }

    void Click()
    {
        if (onClick)
        {
            onClick();
        }
    }

private:
    ClickHandler onClick;
};

int main()
{
    Button button;
    int clickCount = 0;

    button.SetOnClick([&clickCount]
    {
        ++clickCount;
    });

    button.Click();
    button.Click();

    std::cout << clickCount << '\n';
}
