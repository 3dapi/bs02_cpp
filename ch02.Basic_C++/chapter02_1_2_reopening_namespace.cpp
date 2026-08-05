#include <iostream>

namespace Game
{
    void Initialize()
    {
        std::cout << "Initialize\n";
    }
}
namespace Game
{
    void Update()
    {
        std::cout << "Update\n";
    }
}

int main()
{
    Game::Initialize();
    Game::Update();
}
