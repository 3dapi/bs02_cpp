#include <iostream>

class GameObject
{
public:
    virtual ~GameObject() = default;

    void Update()
    {
        if (!active)
        {
            return;
        }

        OnUpdate();
    }

    void SetActive(bool active)
    {
        this->active = active;
    }

protected:
    virtual void OnUpdate() = 0;

private:
    bool active = true;
};

class Monster : public GameObject
{
protected:
    void OnUpdate() override
    {
        std::cout << "Monster Think\n";
    }
};

int main()
{
    Monster monster;
    monster.Update();
    monster.SetActive(false);
    monster.Update();
}
