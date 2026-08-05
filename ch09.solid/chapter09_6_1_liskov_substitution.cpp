#include <iostream>
#include <stdexcept>

class IMovable
{
public:
    virtual ~IMovable() = default;

    virtual void MoveTo(float x, float y) = 0;
    virtual float GetX() const = 0;
    virtual float GetY() const = 0;
};

class Player : public IMovable
{
public:
    void MoveTo(float x, float y) override
    {
        this->x = x;
        this->y = y;
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
    float x = 0.0f, y = 0.0f;
};

void MoveToOrigin(IMovable& object)
{
    object.MoveTo(0.0f, 0.0f);

    if (object.GetX() != 0.0f ||
        object.GetY() != 0.0f)
    {
        throw std::runtime_error("object did not move");
    }
}

int main()
{
    Player player;
    player.MoveTo(10.0f, 20.0f);
    MoveToOrigin(player);

    std::cout << player.GetX() << ' '
              << player.GetY() << '\n';
}
