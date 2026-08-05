#include <iostream>

class Player
{
public:
    void TakeDamage(int damage)
    {
        hp -= damage;
    }

    int Hp() const
    {
        return hp;
    }

private:
    int hp = 100;
};

class BattleSystem
{
public:
    explicit BattleSystem(Player& player)
        : player(player)
    {
    }

    void Attack(int damage)
    {
        player.TakeDamage(damage);
    }

private:
    Player& player;
};

class Enemy
{
public:
    void SetTarget(Player* target)
    {
        this->target = target;
    }

    void Attack() const
    {
        if (target != nullptr)
        {
            target->TakeDamage(10);
        }
    }

private:
    Player* target = nullptr;
};

int main()
{
    Player player;
    BattleSystem battle(player);
    Enemy enemy;

    battle.Attack(20);

    enemy.SetTarget(&player);
    enemy.Attack();

    std::cout << player.Hp() << '\n';
}
