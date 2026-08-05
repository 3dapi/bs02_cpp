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
};

int main()
{
    Enemy* enemy = nullptr;

    {
        Enemy localEnemy;
        enemy = &localEnemy;

        std::cout << "객체 사용 가능: "
                  << static_cast<const void*>(enemy)
                  << '\n';
    }

    enemy = nullptr;

    std::cout << "객체 수명 종료\n";
}
