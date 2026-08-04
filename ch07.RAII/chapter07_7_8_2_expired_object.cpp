#include <iostream>
#include <memory>

class Texture
{
};

int main()
{
    std::weak_ptr<Texture> observer;

    {
        auto texture =
            std::make_shared<Texture>();

        observer = texture;

        std::cout << std::boolalpha;
        std::cout << observer.expired() << '\n';
    }

    std::cout << observer.expired() << '\n';
}
