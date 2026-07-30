#include <iostream>

class Target
{
public:
    void Reset()
    {
        value = 0;
    }

    int Value() const
    {
        return value;
    }

private:
    int value = 100;
};

class TargetView
{
public:
    TargetView(Target* target)
        : target(target)
    {
    }

    void ResetTarget() const
    {
        if (target != nullptr)
        {
            target->Reset();
        }
    }

private:
    Target* target = nullptr;
};

int main()
{
    Target target;
    const TargetView view(&target);

    view.ResetTarget();
    std::cout << target.Value() << '\n';
}
