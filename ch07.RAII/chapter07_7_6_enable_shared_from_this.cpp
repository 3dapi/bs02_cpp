#include <iostream>
#include <memory>

class GameObject
    : public std::enable_shared_from_this<GameObject>
{
public:
    std::shared_ptr<GameObject> GetShared()
    {
        return shared_from_this();
    }
};

int main()
{
    auto object = std::make_shared<GameObject>();
    auto sameObject = object->GetShared();

    std::cout << std::boolalpha;
    std::cout << (object.get()
                  == sameObject.get()) << '\n';
    std::cout << object.use_count() << '\n';
}
