#include <iostream>
#include <memory>
#include <stdexcept>

class Resource
{
public:
    Resource()
    {
        std::cout << "Resource 생성\n";
    }

    ~Resource()
    {
        std::cout << "Resource 소멸\n";
    }
};

void LoadLevel()
{
    std::unique_ptr<Resource> resource =
        std::make_unique<Resource>();

    throw std::runtime_error("실패");
}

int main()
{
    try
    {
        LoadLevel();
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }
}
