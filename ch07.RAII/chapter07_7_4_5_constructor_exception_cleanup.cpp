#include <iostream>
#include <stdexcept>
#include <string>

class MemberResource
{
public:
    MemberResource(
        const std::string& name,
        bool fail
    )
        : name(name)
    {
        std::cout << name << " 생성 시작\n";

        if (fail)
        {
            throw std::runtime_error(
                name + " 생성 실패"
            );
        }

        std::cout << name << " 생성 완료\n";
    }

    ~MemberResource()
    {
        std::cout << name << " 소멸\n";
    }

private:
    std::string name;
};

class LevelPackage
{
public:
    LevelPackage()
        : config("config", false),
          map("map", true)
    {
    }

    ~LevelPackage()
    {
        std::cout << "LevelPackage 소멸\n";
    }

private:
    MemberResource config;
    MemberResource map;
};

int main()
{
    try
    {
        LevelPackage package;
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }
}
