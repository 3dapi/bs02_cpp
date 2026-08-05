#include <iostream>

class IGameEntity
{
public:
    virtual ~IGameEntity() = default;

    virtual void Update() = 0;
    virtual void Render() const = 0;
    virtual void ProcessInput() = 0;
    virtual int TakeDamage(int damage) = 0;
    virtual void Save() const = 0;
};

class Wall : public IGameEntity
{
public:
    void Update() override
    {
    }

    void Render() const override
    {
        std::cout << "wall render\n";
    }

    void ProcessInput() override
    {
    }

    int TakeDamage(int) override
    {
        return 0;
    }

    void Save() const override
    {
    }
};

int main()
{
    Wall wall;
    wall.Render();
}
