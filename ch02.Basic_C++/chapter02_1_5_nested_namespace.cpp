#include <iostream>

namespace Game::System::Audio
{
    void Initialize()
    {
        std::cout << "Audio\n";
    }
}

int main()
{
    Game::System::Audio::Initialize();
}
