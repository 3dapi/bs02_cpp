#include <iostream>

class GameObject
{
public:
    GameObject()
    {
        Initialize();
    }

    virtual ~GameObject()
    {
        Shutdown();
    }

    virtual void Initialize()
    {
        std::cout << "GameObject Initialize\n";
    }

    virtual void Shutdown()
    {
        std::cout << "GameObject Shutdown\n";
    }
};

class Player : public GameObject
{
public:
    Player()
    {
        std::cout << "Player 생성자\n";
    }

    ~Player() override
    {
        std::cout << "Player 소멸자\n";
    }

    void Initialize() override
    {
        std::cout << "Player Initialize\n";
    }

    void Shutdown() override
    {
        std::cout << "Player Shutdown\n";
    }
};

int main()
{
    Player player;
}
