#include <chrono>
#include <iostream>

using Seconds = std::chrono::duration<double>;

class Object
{
public:
    void Update(Seconds deltaTime)
    {
        position += speed * deltaTime.count();
    }

    double GetPosition() const
    {
        return position;
    }

private:
    double position = 0.0;
    double speed = 10.0;
};

int main()
{
    Object object;
    object.Update(Seconds{0.5});
    std::cout << object.GetPosition() << '\n';
}
