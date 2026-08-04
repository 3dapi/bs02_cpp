#include <iostream>

class MovementService
{
public:
    void Move() const
    {
        std::cout << "movement service\n";
    }
};

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update() = 0;
};

class Player : public GameObject
{
public:
    void Update() override
    {
        movement.Move();
    }

private:
    MovementService movement;
};

int main()
{
    Player player;
    GameObject& object = player;
    object.Update();
}
