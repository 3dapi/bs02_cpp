#include <iostream>
#include <string>

class Trace
{
public:
    Trace(const std::string& name)
        : name(name)
    {
        std::cout << name << " 생성\n";
    }

    ~Trace()
    {
        std::cout << name << " 소멸\n";
    }

private:
    std::string name;
};

void Test(bool stop)
{
    Trace trace("trace");

    if (stop)
    {
        return;
    }

    std::cout << "함수 계속 실행\n";
}

int main()
{
    Test(true);
}
