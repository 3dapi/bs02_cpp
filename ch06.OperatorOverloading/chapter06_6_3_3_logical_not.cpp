#include <iostream>

class ResourceHandle
{
public:
    explicit ResourceHandle(void* handle)
        : handle(handle)
    {
    }

    bool operator!() const
    {
        return handle == nullptr;
    }

public:
    void* handle = nullptr;
};

int main()
{
    int resource = 10;

    ResourceHandle valid(&resource);
    ResourceHandle invalid(nullptr);

    std::cout << std::boolalpha;
    std::cout << !valid << '\n';
    std::cout << !invalid << '\n';
}
