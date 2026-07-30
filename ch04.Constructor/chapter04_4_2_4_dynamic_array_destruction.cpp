#include <iostream>

class Sample
{
public:
    Sample()
    {
        std::cout << "생성: " << this << '\n';
    }

    ~Sample()
    {
        std::cout << "소멸: " << this << '\n';
    }
};

int main()
{
    Sample* samples = new Sample[3];

    delete[] samples;
}
