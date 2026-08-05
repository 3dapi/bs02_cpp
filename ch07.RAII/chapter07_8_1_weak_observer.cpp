#include <iostream>
#include <memory>

class Texture
{
};

int main()
{
    std::shared_ptr<Texture> texture =
        std::make_shared<Texture>();

    std::weak_ptr<Texture> observer = texture;

    std::cout << std::boolalpha;
    std::cout << observer.expired() << '\n';

    texture.reset();

    std::cout << observer.expired() << '\n';
}
