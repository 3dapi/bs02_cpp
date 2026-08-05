#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

class Texture
{
public:
    explicit Texture(std::string fileName)
        : fileName(std::move(fileName))
    {
    }

    void Bind() const
    {
        std::cout << "Texture 바인딩: "
                  << fileName << '\n';
    }

private:
    std::string fileName;
};

class Sprite
{
public:
    Sprite(
        std::string name,
        std::shared_ptr<Texture> texture
    )
        : name(std::move(name)),
          texture(std::move(texture))
    {
        if (this->texture == nullptr)
        {
            throw std::invalid_argument(
                "Sprite에는 Texture가 필요합니다."
            );
        }
    }

    void Draw() const
    {
        texture->Bind();

        std::cout << "Sprite 출력: "
                  << name << '\n';
    }

private:
    std::string name;
    std::shared_ptr<Texture> texture;
};

int main()
{
    auto texture =
        std::make_shared<Texture>("character.png");

    Sprite idle("HeroIdle", texture);
    Sprite run("HeroRun", texture);

    idle.Draw();
    run.Draw();
}
