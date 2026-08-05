#include <iostream>
#include <stdexcept>
#include <string>

class TraceObject
{
public:
    explicit TraceObject(const std::string& name)
        : name(name)
    {
        std::cout << name << " 생성\n";
    }

    ~TraceObject()
    {
        std::cout << name << " 소멸\n";
    }

private:
    std::string name;
};

void LoadLevel()
{
    TraceObject first("first");
    TraceObject second("second");

    throw std::runtime_error("레벨 로드 실패");
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
