#include <iostream>

class Trace
{
public:
    explicit Trace(const char* name)
        : name(name)
    {
        std::cout << name << " 초기화\n";
    }

private:
    const char* name;
};

class Base
{
public:
    Base()
        : baseTrace("Base")
    {
    }

private:
    Trace baseTrace;
};

class Derived : public Base
{
public:
    Derived()
        : Base(), first("first"), second("second")
    {
        std::cout << "Derived 본문\n";
    }

private:
    Trace first;
    Trace second;
};

int main()
{
    Derived object;
}
