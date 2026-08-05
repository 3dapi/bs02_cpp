#include <iostream>
#include <string>

class Label
{
public:
    Label(const std::string& text)
        : text(text)
    {
    }

    void Print() const
    {
        std::cout << text << '\n';
    }

private:
    std::string text;
};

int main()
{
    Label label("Start");
    label.Print();
}
