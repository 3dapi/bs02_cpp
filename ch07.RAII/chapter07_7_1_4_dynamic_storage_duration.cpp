#include <iostream>

class Enemy
{
public:
    Enemy()
    {
        std::cout << "Enemy 생성\n";
    }

    ~Enemy()
    {
        std::cout << "Enemy 소멸\n";
    }

    void Update() const
    {
        std::cout << "Enemy 갱신\n";
    }
};

int main()
{
    Enemy* enemy = new Enemy;

    enemy->Update();

    delete enemy;
    enemy = nullptr;
}
