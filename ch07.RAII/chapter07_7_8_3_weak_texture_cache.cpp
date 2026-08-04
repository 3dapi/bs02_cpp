#include <iostream>
#include <map>
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

    const std::string& Name() const
    {
        return name;
    }

private:
    std::string name;
};

class TextureCache
{
public:
    void Store(
        const std::string& name,
        const std::shared_ptr<Texture>& texture
    )
    {
        textures[name] = texture;
    }

    std::shared_ptr<Texture> Find(
        const std::string& name
    ) const
    {
        auto found = textures.find(name);

        if (found == textures.end())
        {
            return nullptr;
        }

        return found->second.lock();
    }

private:
    std::map<
        std::string,
        std::weak_ptr<Texture>
    > textures;
};

int main()
{
    TextureCache cache;

    auto texture =
        std::make_shared<Texture>("hero.png");

    cache.Store("hero.png", texture);

    if (auto found = cache.Find("hero.png"))
    {
        std::cout << found->Name() << '\n';
    }

    texture.reset();

    std::cout << std::boolalpha;
    std::cout << static_cast<bool>(
        cache.Find("hero.png")
    ) << '\n';
}
