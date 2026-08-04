#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class GameObject
{
public:
    explicit GameObject(int id)
        : id(id)
    {
    }

    virtual ~GameObject() = default;
    virtual void Update() = 0;

    int GetId() const
    {
        return id;
    }

private:
    int id;
};

class Player : public GameObject
{
public:
    explicit Player(int id)
        : GameObject(id)
    {
    }

    void Update() override
    {
        std::cout << "Player Update\n";
    }
};

class Monster : public GameObject
{
public:
    explicit Monster(int id)
        : GameObject(id)
    {
    }

    void Update() override
    {
        std::cout << "Monster Update\n";
    }
};

class GameScene
{
public:
    void Add(std::unique_ptr<GameObject> object)
    {
        if (object != nullptr)
        {
            objects.push_back(std::move(object));
        }
    }

    void UpdateAll()
    {
        for (const auto& object : objects)
        {
            object->Update();
        }
    }

    GameObject* FindById(int id)
    {
        for (const auto& object : objects)
        {
            if (object->GetId() == id)
            {
                return object.get();
            }
        }

        return nullptr;
    }

private:
    std::vector<std::unique_ptr<GameObject>> objects;
};

int main()
{
    GameScene scene;
    scene.Add(std::make_unique<Player>(1));
    scene.Add(std::make_unique<Monster>(2));

    scene.UpdateAll();
    std::cout << std::boolalpha
              << (scene.FindById(2) != nullptr) << '\n';
}
