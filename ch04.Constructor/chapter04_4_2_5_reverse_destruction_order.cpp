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

int main()
{
    Trace first("first");
    Trace second("second");
    Trace third("third");
}
