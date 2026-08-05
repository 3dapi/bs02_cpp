#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update() = 0;
    virtual void Render() const = 0;
};

class Player : public GameObject
{
public:
    void Update() override
    {
        std::cout << "Player Update\n";
    }

    void Render() const override
    {
        std::cout << "Player Render\n";
    }
};

void ProcessObject(GameObject& object)
{
    object.Update();
    object.Render();
}

int main()
{
    Player player;
    ProcessObject(player);
}
