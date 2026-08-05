#include <iostream>

class Character
{
public:
    enum class State
    {
        Idle,
        Move,
        Attack,
        Dead
    };

    void SetState(State newState)
    {
        state = newState;
    }

    State GetState() const
    {
        return state;
    }

private:
    State state = State::Idle;
};

int main()
{
    Character character;

    character.SetState(Character::State::Attack);

    std::cout << static_cast<int>(character.GetState()) << '\n';
}
