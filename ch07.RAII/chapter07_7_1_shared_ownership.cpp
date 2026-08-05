#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Texture
{
public:
    explicit Texture(std::string name)
        : name(std::move(name))
    {
    }

    void Bind() const
    {
        std::cout << name << '\n';
    }

private:
    std::string name;
};

class Sprite
{
public:
    explicit Sprite(
        std::shared_ptr<Texture> texture
    )
        : texture(std::move(texture))
    {
    }

    void Draw() const
    {
        texture->Bind();
    }

private:
    std::shared_ptr<Texture> texture;
};

int main()
{
    auto texture =
        std::make_shared<Texture>("character.png");

    Sprite idle(texture);
    Sprite run(texture);
    Sprite attack(texture);

    idle.Draw();
    run.Draw();
    attack.Draw();
}
