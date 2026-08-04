#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>

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

int main()
{
    TextureCache cache;

    {
        auto first = cache.Load("character.png");
        auto second = cache.Load("character.png");

        std::cout << cache.EntryCount() << '\n';
    }

    cache.RemoveExpired();

    std::cout << cache.EntryCount() << '\n';
}
