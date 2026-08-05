#include <iostream>

class IUpdatable
{
public:
    virtual ~IUpdatable() = default;
    virtual void Update() = 0;
};

class IInputReceiver
{
public:
    virtual ~IInputReceiver() = default;
    virtual void ProcessInput() = 0;
};

class Player : public IUpdatable, public IInputReceiver
{
public:
    void Update() override
    {
        std::cout << "Player Update\n";
    }

    void ProcessInput() override
    {
        std::cout << "Player Input\n";
    }
};

class Monster : public IUpdatable
{
public:
    void Update() override
    {
        std::cout << "Monster Update\n";
    }
};

int main()
{
    Player player;
    Monster monster;

    IUpdatable& first = player;
    IUpdatable& second = monster;
    IInputReceiver& input = player;

    first.Update();
    second.Update();
    input.ProcessInput();
}
