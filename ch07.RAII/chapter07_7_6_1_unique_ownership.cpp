#include <iostream>
#include <memory>

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
    std::unique_ptr<Enemy> enemy =
        std::make_unique<Enemy>();

    enemy->Update();

    if (enemy)
    {
        std::cout << "Enemy 소유 중\n";
    }
}
