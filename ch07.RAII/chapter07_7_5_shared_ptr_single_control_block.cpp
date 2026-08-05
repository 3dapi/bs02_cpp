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
    auto first =
        std::make_shared<Texture>("hero.png");

    auto second = first;
    Texture* observed = first.get();

    std::cout << observed->FileName() << '\n';
    std::cout << second.use_count() << '\n';
}
