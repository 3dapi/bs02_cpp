#include <iostream>

class ResourceHandle
{
public:
    explicit ResourceHandle(void* handle)
        : handle(handle)
    {
    }

    explicit operator bool() const noexcept
    {
        return handle != nullptr;
    }

private:
    void* handle = nullptr;
};

int main()
{
    int resource = 10;

    ResourceHandle valid(&resource);
    ResourceHandle invalid(nullptr);

    if (valid)
    {
        std::cout << "자원을 사용할 수 있음\n";
    }

    if (!invalid)
    {
        std::cout << "자원이 없음\n";
    }

    bool state = static_cast<bool>(valid);
    std::cout << std::boolalpha << state << '\n';
}
