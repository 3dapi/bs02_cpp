#include <iostream>

namespace Audio
{
    void Initialize()
    {
        std::cout << "오디오 시스템 초기화\n";
    }
}
namespace Graphics
{
    void Initialize()
    {
        std::cout << "그래픽스 시스템 초기화\n";
    }
}

int main()
{
    Audio::Initialize();
    Graphics::Initialize();
}
