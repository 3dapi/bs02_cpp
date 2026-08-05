#include <iostream>

class GameConfig
{
public:
    inline static int maxStage = 10;
};

int main()
{
    std::cout << GameConfig::maxStage << '\n';

    GameConfig::maxStage = 20;
    std::cout << GameConfig::maxStage << '\n';
}
