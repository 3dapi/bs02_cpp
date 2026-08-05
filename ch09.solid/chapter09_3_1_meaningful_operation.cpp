#include <iostream>

class Weapon
{
public:
    void Fire(int targetId)
    {
        ConsumeAmmo();
        StartCooldown();
        PlayAnimation();

        std::cout << "fire target=" << targetId << '\n';
    }

private:
    void ConsumeAmmo()
    {
        --ammo;
    }

    void StartCooldown()
    {
        coolingDown = true;
    }

    void PlayAnimation()
    {
        std::cout << "play animation\n";
    }

    int ammo = 10;
    bool coolingDown = false;
};

int main()
{
    Weapon weapon;
    weapon.Fire(1001);
}
