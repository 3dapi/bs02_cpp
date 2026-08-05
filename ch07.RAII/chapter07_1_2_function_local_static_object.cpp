#include <iostream>

class GameConfig
{
public:
    GameConfig()
    {
        std::cout << "GameConfig 생성\n";
    }

    void Print() const
    {
        std::cout << "GameConfig 사용\n";
    }
};

GameConfig& GetConfig()
{
    static GameConfig config;
    return config;
}

int main()
{
    GetConfig().Print();
    GetConfig().Print();
}
