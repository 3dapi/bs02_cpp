#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    virtual void Draw(int layer = 0) const
    {
        std::cout << "GameObject layer: " << layer << '\n';
    }
};

class Player : public GameObject
{
public:
    void Draw(int layer = 10) const override
    {
        std::cout << "Player layer: " << layer << '\n';
    }
};

int main()
{
    Player player;
    GameObject& object = player;

    player.Draw();
    object.Draw();
}
