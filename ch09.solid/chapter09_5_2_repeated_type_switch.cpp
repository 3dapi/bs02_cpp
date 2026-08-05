#include <iostream>

class Player
{
public:
    enum class AttackType
    {
        Melee,
        Ranged
    };

    void Attack() const
    {
        switch (attackType)
        {
        case AttackType::Melee:
            std::cout << "melee damage\n";
            break;

        case AttackType::Ranged:
            std::cout << "ranged damage\n";
            break;
        }
    }

    void PlayAttackSound() const
    {
        switch (attackType)
        {
        case AttackType::Melee:
            std::cout << "sword sound\n";
            break;

        case AttackType::Ranged:
            std::cout << "bow sound\n";
            break;
        }
    }

    void DrawAttackIcon() const
    {
        switch (attackType)
        {
        case AttackType::Melee:
            std::cout << "sword icon\n";
            break;

        case AttackType::Ranged:
            std::cout << "bow icon\n";
            break;
        }
    }

private:
    AttackType attackType = AttackType::Melee;
};

int main()
{
    Player player;

    player.Attack();
    player.PlayAttackSound();
    player.DrawAttackIcon();
}
