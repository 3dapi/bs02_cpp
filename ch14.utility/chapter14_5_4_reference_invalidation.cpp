#include <functional>
#include <iostream>
#include <vector>

struct Player
{
    int hp;
};

int main()
{
    std::vector<Player> players;
    players.reserve(2);
    players.push_back({100});
    players.push_back({80});

    std::reference_wrapper<Player> selected = players[0];
    const Player* oldAddress = &selected.get();

    players.push_back({90});
    const Player* newAddress = &players[0];

    std::cout << std::boolalpha
              << (oldAddress == newAddress)
              << '\n';

    // 주소가 달라졌다면 selected는 더 이상 사용하지 않는다.
}
