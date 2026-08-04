#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Texture
{
public:
    explicit Texture(std::string fileName)
        : fileName(std::move(fileName)),
          id(++nextId)
    {
        if (this->fileName.empty())
        {
            throw std::invalid_argument(
                "텍스처 파일 이름이 비어 있습니다."
            );
        }

        std::cout << "Texture 생성: "
                  << this->fileName
                  << " (" << id << ")\n";
    }

    ~Texture()
    {
        std::cout << "Texture 소멸: "
                  << fileName
                  << " (" << id << ")\n";
    }

    void Bind() const
    {
        std::cout << "Texture 바인딩: "
                  << fileName << '\n';
    }

private:
    inline static int nextId = 0;

    std::string fileName;
    int id;
};

class TextureCache
{
public:
    std::shared_ptr<Texture> Load(
        const std::string& fileName
    )
    {
        auto found = textures.find(fileName);

        if (found != textures.end())
        {
            if (auto texture = found->second.lock())
            {
                std::cout << "Texture 재사용: "
                          << fileName << '\n';

                return texture;
            }
        }

        auto texture =
            std::make_shared<Texture>(fileName);

        textures[fileName] = texture;

        return texture;
    }

    void RemoveExpired()
    {
        for (auto iterator = textures.begin();
             iterator != textures.end();)
        {
            if (iterator->second.expired())
            {
                iterator = textures.erase(iterator);
            }
            else
            {
                ++iterator;
            }
        }
    }

    std::size_t EntryCount() const
    {
        return textures.size();
    }

private:
    std::unordered_map<
        std::string,
        std::weak_ptr<Texture>
    > textures;
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

        std::cout << "Sprite 생성: "
                  << this->name << '\n';
    }

    ~Sprite()
    {
        std::cout << "Sprite 소멸: "
                  << name << '\n';
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

private:
    std::vector<std::unique_ptr<Sprite>> sprites;
};

std::unique_ptr<Sprite> CreateSprite(
    TextureCache& cache,
    const std::string& name,
    const std::string& textureFile
)
{
    return std::make_unique<Sprite>(
        name,
        cache.Load(textureFile)
    );
}

int main()
{
    TextureCache cache;

    try
    {
        {
            GameScene scene;

            scene.AddSprite(CreateSprite(
                cache,
                "HeroIdle",
                "character.png"
            ));

            scene.AddSprite(CreateSprite(
                cache,
                "HeroRun",
                "character.png"
            ));

            scene.AddSprite(CreateSprite(
                cache,
                "Background",
                "forest.png"
            ));

            std::cout << "--- Draw ---\n";

            scene.Draw();

            std::cout << "cache entries: "
                      << cache.EntryCount()
                      << '\n';
        }

        std::cout << "--- Scene 소멸 후 ---\n";

        cache.RemoveExpired();

        std::cout << "cache entries: "
                  << cache.EntryCount()
                  << '\n';
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }
}
