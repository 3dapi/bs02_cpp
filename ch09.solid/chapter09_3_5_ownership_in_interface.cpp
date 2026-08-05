#include <iostream>
#include <memory>
#include <vector>

class GameObject
{
public:
    explicit GameObject(int id)
        : id(id)
    {
    }

    int GetId() const
    {
        return id;
    }

private:
    int id;
};

void Render(const GameObject& object)
{
    std::cout << object.GetId() << '\n';
}

class GameScene
{
public:
    void AddObject(std::unique_ptr<GameObject> object)
    {
        objects.push_back(std::move(object));
    }

private:
    std::vector<std::unique_ptr<GameObject>> objects;
};

std::unique_ptr<GameObject> CreateObject()
{
    return std::make_unique<GameObject>(100);
}

int main()
{
    std::unique_ptr<GameObject> object = CreateObject();
    Render(*object);

    GameScene scene;
    scene.AddObject(std::move(object));
}
