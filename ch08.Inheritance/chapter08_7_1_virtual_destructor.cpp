#include <iostream>
#include <memory>

class GameObject
{
public:
    virtual ~GameObject()
    {
        std::cout << "GameObject 소멸\n";
    }
};

class Player : public GameObject
{
public:
    ~Player() override
    {
        std::cout << "Player 소멸\n";
    }
};

int main()
{
    std::unique_ptr<GameObject> object =
        std::make_unique<Player>();
}
