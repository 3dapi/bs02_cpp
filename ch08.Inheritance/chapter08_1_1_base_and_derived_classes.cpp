#include <iostream>

class GameObject
{
public:
    void SetPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float GetX() const
    {
        return x;
    }

    float GetY() const
    {
        return y;
    }

protected:
    float x = 0.0f, y = 0.0f;
};

class Character : public GameObject
{
public:
    void TakeDamage(int damage)
    {
        if (damage > 0)
        {
            hp -= damage;

            if (hp < 0)
            {
                hp = 0;
            }
        }
    }

    int GetHp() const
    {
        return hp;
    }

protected:
    int hp = 100;
};

class Player : public Character
{
public:
    void AddScore(int value)
    {
        if (value > 0)
        {
            score += value;
        }
    }

    int GetScore() const
    {
        return score;
    }

private:
    int score = 0;
};

int main()
{
    Player player;
    player.SetPosition(100.0f, 200.0f);
    player.TakeDamage(20);
    player.AddScore(500);

    std::cout << player.GetX() << ", "
              << player.GetY() << '\n';
    std::cout << player.GetHp() << '\n';
    std::cout << player.GetScore() << '\n';
}
