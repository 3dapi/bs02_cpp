#include <iostream>
#include <string>

class Trace
{
public:
    Trace(const std::string& name)
    {
        this->name = name;
        std::cout << name << " 생성\n";
    }

    ~Trace()
    {
        std::cout << name << " 소멸\n";
    }

private:
    std::string name;
};

int main()
{
    Trace trace("local");

    std::cout << "main 실행 중\n";
}
