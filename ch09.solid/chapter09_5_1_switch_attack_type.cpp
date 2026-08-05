#include <iostream>

class Player
{
public:
    enum class AttackType
    {
        Melee,
        Ranged
    };

    int CalculateDamage() const
    {
        switch (attackType)
        {
        case AttackType::Melee:
            return strength * 2;

        case AttackType::Ranged:
            return dexterity + arrowPower;
        }

        return 0;
    }

    void SetAttackType(AttackType attackType)
    {
        this->attackType = attackType;
    }

private:
    AttackType attackType = AttackType::Melee;
    int strength = 10;
    int dexterity = 8;
    int arrowPower = 5;
};

int main()
{
    Player player;
    std::cout << player.CalculateDamage() << '\n';

    player.SetAttackType(Player::AttackType::Ranged);
    std::cout << player.CalculateDamage() << '\n';
}
