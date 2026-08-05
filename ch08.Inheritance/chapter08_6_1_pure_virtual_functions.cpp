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

int main()
{
    Player player;
    GameObject& object = player;
    object.Update();
    object.Render();
}
