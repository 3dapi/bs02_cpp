#include <iostream>

class Character
{
public:
    void SetPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

protected:
    float x = 0.0f, y = 0.0f;
};

class InternalCharacter : protected Character
{
public:
    void ResetPosition()
    {
        SetPosition(0.0f, 0.0f);
    }

    void PrintPosition() const
    {
        std::cout << x << ", " << y << '\n';
    }
};

int main()
{
    InternalCharacter object;
    object.ResetPosition();
    object.PrintPosition();
}
