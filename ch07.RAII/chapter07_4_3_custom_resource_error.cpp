#include <iostream>
#include <stdexcept>
#include <string>

class ResourceError : public std::runtime_error
{
public:
    ResourceError(
        const std::string& resourceName,
        const std::string& message
    )
        : std::runtime_error(message),
          resourceName(resourceName)
    {
    }

    const std::string& ResourceName() const
    {
        return resourceName;
    }

private:
    std::string resourceName;
};

void LoadTexture(const std::string& fileName)
{
    throw ResourceError(
        fileName,
        "텍스처 파일을 찾을 수 없습니다."
    );
}

int main()
{
    try
    {
        LoadTexture("hero.png");
    }
    catch (const ResourceError& error)
    {
        std::cerr << "resource: "
                  << error.ResourceName() << '\n';
        std::cerr << error.what() << '\n';
    }
}
