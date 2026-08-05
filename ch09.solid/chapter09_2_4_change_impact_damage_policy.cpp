#include <iostream>

class LevelDamagePolicy
{
public:
    int Calculate(int attackPower, int level) const
    {
        return attackPower + level * 3;
    }
};

int main()
{
    LevelDamagePolicy policy;

    std::cout << policy.Calculate(20, 5) << '\n';
}
