#include <iostream>
#include <string>
#include <utility>

class Character
{
public:
    Character(int id, std::string name, int hp)
        : id(id), name(std::move(name)), hp(hp)
    {
    }

    void Print() const
    {
        std::cout << id << ": " << name
                  << ", hp=" << hp << '\n';
    }

private:
    int id;
    std::string name;
    int hp;
};

class Monster : public Character
{
public:
    Monster(int id,
            std::string name,
            int hp,
            int attackPower,
            int patrolRange)
        : Character(id, std::move(name), hp),
          attackPower(attackPower),
          patrolRange(patrolRange)
    {
    }

    void PrintDetails() const
    {
        Print();
        std::cout << attackPower << ", "
                  << patrolRange << '\n';
    }

private:
    int attackPower;
    int patrolRange;
};

int main()
{
    Monster monster(2, "Goblin", 60, 10, 5);
    monster.PrintDetails();
}
