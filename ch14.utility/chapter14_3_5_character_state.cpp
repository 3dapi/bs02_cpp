#include <iostream>
#include <variant>

struct Idle
{
};

struct Moving
{
    float speed;
};

struct Attacking
{
    int targetId;
    int damage;
};

template <typename... Functions>
struct Overloaded : Functions...
{
    using Functions::operator()...;
};

template <typename... Functions>
Overloaded(Functions...) -> Overloaded<Functions...>;

using CharacterState = std::variant<Idle, Moving, Attacking>;

void UpdateState(CharacterState& state)
{
    std::visit(
        Overloaded{
            [](Idle&)
            {
                std::cout << "idle\n";
            },
            [](Moving& moving)
            {
                std::cout << "speed: " << moving.speed << '\n';
            },
            [](Attacking& attacking)
            {
                std::cout << "target: " << attacking.targetId
                          << " damage: " << attacking.damage << '\n';
            }
        },
        state);
}

int main()
{
    CharacterState state = Idle{};
    UpdateState(state);

    state = Moving{3.5f};
    UpdateState(state);

    state = Attacking{42, 15};
    UpdateState(state);
}
