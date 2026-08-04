#include <iostream>

class IMovable
{
public:
    virtual ~IMovable() = default;

    virtual void MoveTo(float x, float y) = 0;
    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
};

class Wall : public IMovable
{
public:
    void MoveTo(float, float) override
    {
        // 벽은 움직이지 않음
    }

    float GetX() const override
    {
        return x;
    }

    float GetY() const override
    {
        return y;
    }

private:
    float x = 10.0f, y = 20.0f;
};

int main()
{
    Wall wall;
    wall.MoveTo(0.0f, 0.0f);

    std::cout << wall.GetX() << ' '
              << wall.GetY() << '\n';
}
