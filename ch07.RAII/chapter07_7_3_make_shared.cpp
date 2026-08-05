#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Texture
{
public:
    explicit Texture(std::string fileName)
        : fileName(std::move(fileName))
    {
    }

    const std::string& FileName() const
    {
        return fileName;
    }

private:
    std::string fileName;
};

int main()
{
    auto texture =
        std::make_shared<Texture>("hero.png");

    std::cout << texture->FileName() << '\n';
}
