#include <iostream>

struct Vector2
{
    float x = 0.0f, y = 0.0f;
};

class Character
{
public:
    void Move(float offsetX, float offsetY)
    {
        position.x += offsetX;
        position.y += offsetY;
    }

    void TakeDamage(int damage)
    {
        hp -= damage;

        if (hp < 0)
        {
            hp = 0;
        }
    }

    int GetHp() const
    {
        return hp;
    }

protected:
    Vector2 position;
    int hp = 100;
};

class Player : public Character
{
public:
    void LevelUp()
    {
        ++level;
    }

private:
    int level = 1;
};

class Enemy : public Character
{
public:
    void Update()
    {
        std::cout << "Enemy Update\n";
    }

private:
    int reward = 100;
};

int main()
{
    Player player;
    Enemy enemy;

    player.Move(10.0f, 20.0f);
    enemy.TakeDamage(30);
    enemy.Update();

    std::cout << enemy.GetHp() << '\n';
}
