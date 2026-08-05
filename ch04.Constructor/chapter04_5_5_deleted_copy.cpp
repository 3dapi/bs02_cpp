#include <iostream>

class Resource
{
public:
    Resource() = default;

    Resource(const Resource&) = delete;
    Resource& operator=(const Resource&) = delete;

    void Use() const
    {
        std::cout << "resource 사용\n";
    }
};

int main()
{
    Resource resource;
    resource.Use();

    // Resource copy = resource;   // 오류
}
