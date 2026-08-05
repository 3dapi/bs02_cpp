#include <iostream>
#include <memory>

class Texture
{
};

int main()
{
    auto first = std::make_shared<Texture>();
    auto second = first;

    std::cout << first.use_count() << '\n';

    second.reset();

    std::cout << first.use_count() << '\n';
}
