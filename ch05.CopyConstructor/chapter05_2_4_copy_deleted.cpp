#include <iostream>

class UniqueResource
{
public:
    UniqueResource() = default;

    UniqueResource(const UniqueResource&) = delete;
    UniqueResource& operator=(const UniqueResource&) = delete;

    bool IsValid() const
    {
        return true;
    }
};

int main()
{
    UniqueResource resource;

    // UniqueResource copy = resource;  // 오류

    std::cout << std::boolalpha << resource.IsValid() << '\n';
}
