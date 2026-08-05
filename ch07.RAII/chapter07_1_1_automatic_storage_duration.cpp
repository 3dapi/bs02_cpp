#include <iostream>
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

void TestScope()
{
    TraceObject first("first");
    TraceObject second("second");
}

int main()
{
    TestScope();
}
