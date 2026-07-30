#include <iostream>
#include <utility>

class Resource
{
public:
    Resource() = default;

    Resource(const Resource&) = delete;
    Resource& operator=(const Resource&) = delete;

    Resource(Resource&&) noexcept = default;
    Resource& operator=(Resource&&) noexcept = default;

    bool IsValid() const
    {
        return true;
    }
};

int main()
{
    Resource first;
    Resource second = std::move(first);

    std::cout << std::boolalpha << second.IsValid() << '\n';
}
