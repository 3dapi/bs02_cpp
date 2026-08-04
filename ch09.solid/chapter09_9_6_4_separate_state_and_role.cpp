#include <iostream>

class GameObject
{
public:
    float GetX() const
    {
        return x;
    }

    float GetY() const
    {
        return y;
    }

protected:
    void SetPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

private:
    float x = 0.0f, y = 0.0f;
};

class IMovable
{
public:
    virtual ~IMovable() = default;
    virtual void MoveTo(float x, float y) = 0;
};

class Player : public GameObject, public IMovable
{
public:
    void MoveTo(float x, float y) override
    {
        SetPosition(x, y);
    }
};

class StaticDecoration : public GameObject
{
};

int main()
{
    Player player;
    StaticDecoration decoration;

    player.MoveTo(10.0f, 20.0f);

    std::cout << player.GetX() << ' '
              << player.GetY() << '\n';
    std::cout << decoration.GetX() << ' '
              << decoration.GetY() << '\n';
}
