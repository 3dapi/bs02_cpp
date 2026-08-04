#include <iostream>
#include <memory>

class Texture
{
public:
    void Bind() const
    {
        std::cout << "Texture 바인딩\n";
    }
};

int main()
{
    auto owner = std::make_shared<Texture>();
    std::weak_ptr<Texture> observer = owner;

    if (auto texture = observer.lock())
    {
        texture->Bind();
    }

    owner.reset();

    if (auto texture = observer.lock())
    {
        texture->Bind();
    }
    else
    {
        std::cout << "Texture를 사용할 수 없습니다.\n";
    }
}
