#include <cstddef>
#include <iostream>

template <typename T>
class ObjectCounter
{
public:
    ObjectCounter()
    {
        ++count;
    }

    ObjectCounter(const ObjectCounter&)
    {
        ++count;
    }

    ~ObjectCounter()
    {
        --count;
    }

    static std::size_t GetCount()
    {
        return count;
    }

private:
    inline static std::size_t count = 0;
};

int main()
{
    ObjectCounter<int> first;
    ObjectCounter<int> second;
    ObjectCounter<double> third;

    std::cout << ObjectCounter<int>::GetCount() << '\n';
    std::cout << ObjectCounter<double>::GetCount() << '\n';

    (void)first;
    (void)second;
    (void)third;
}
