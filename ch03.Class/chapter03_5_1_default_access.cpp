#include <iostream>

class ClassTypeSample
{
    int value;
};

struct StructTypeSample
{
    int value;
};

class PublicData
{
public:
    int value;
};

struct PrivateData
{
private:
    int value;
};

int main()
{
    ClassTypeSample first;
    StructTypeSample second;
    PublicData publicData;
    PrivateData privateData;

    // first.value = 10;       // 오류
    second.value = 10;
    publicData.value = 20;
    // privateData.value = 30; // 오류

    std::cout << second.value << '\n';
    std::cout << publicData.value << '\n';

    static_cast<void>(first);
    static_cast<void>(privateData);
}
