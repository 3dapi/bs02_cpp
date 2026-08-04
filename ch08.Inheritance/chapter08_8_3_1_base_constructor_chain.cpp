#include <iostream>
#include <string>
#include <utility>

class GameObject
{
public:
    GameObject(int id, std::string name)
        : id(id), name(std::move(name))
    {
    }

    void Print() const
    {
        std::cout << id << ": " << name << '\n';
    }

private:
    int id;
    std::string name;
};

class Character : public GameObject
{
public:
    Character(int id, std::string name, int hp)
        : GameObject(id, std::move(name)), hp(hp)
    {
    }

    int GetHp() const
    {
        return hp;
    }

private:
    int hp;
};

class Player : public Character
{
public:
    Player(int id, std::string name, int hp)
        : Character(id, std::move(name), hp)
    {
    }
};

int main()
{
    Player player(1, "Knight", 150);
    player.Print();
    std::cout << player.GetHp() << '\n';
}
