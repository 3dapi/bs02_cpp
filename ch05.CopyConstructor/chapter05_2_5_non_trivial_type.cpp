#include <iostream>
#include <string>
#include <type_traits>

struct Player
{
    std::string name;
    int hp;
};

int main()
{
    static_assert(!std::is_trivially_copyable_v<Player>);

    Player first{"Knight", 100};
    Player second = first;

    std::cout << second.name << ", " << second.hp << '\n';
}
