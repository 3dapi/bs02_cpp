#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Sprite
{
public:
    explicit Sprite(std::string name)
        : name(std::move(name))
    {
    }

    void Draw() const
    {
        std::cout << "Sprite 출력: "
                  << name << '\n';
    }

private:
    std::string name;
};

class GameScene
{
public:
    void AddSprite(std::unique_ptr<Sprite> sprite)
    {
        if (sprite == nullptr)
        {
            throw std::invalid_argument(
                "빈 Sprite는 추가할 수 없습니다."
            );
        }

        sprites.push_back(std::move(sprite));
    }

    void Draw() const
    {
        for (const auto& sprite : sprites)
        {
            sprite->Draw();
        }
    }

    std::size_t SpriteCount() const
    {
        return sprites.size();
    }

private:
    std::vector<std::unique_ptr<Sprite>> sprites;
};

int main()
{
    GameScene scene;

    scene.AddSprite(
        std::make_unique<Sprite>("Hero")
    );

    scene.Draw();

    std::cout << scene.SpriteCount() << '\n';
}
