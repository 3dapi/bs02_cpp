#include <iostream>

class Counter
{
public:
    void Increase()
    {
        ++count;
    }

    int GetCount() const
    {
        return count;
    }

private:
    int count = 0;
};

int main()
{
    Counter counter;

    counter.Increase();
    std::cout << counter.GetCount() << '\n';

    // counter.count = 100; // 오류
}
