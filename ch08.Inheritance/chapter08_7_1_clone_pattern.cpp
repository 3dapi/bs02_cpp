#include <iostream>
#include <memory>

static size_t count = 0;

class GameObject
{
public:
    virtual ~GameObject()
    {
        std::cout << ++count <<" GameObject 소멸\n";
    }
    // 기반 클래스에서 가상 복제 함수 선언.
    virtual GameObject* Clone() const = 0;
    //virtual std::unique_ptr<GameObject> Clone() const = 0;
};

class Player : public GameObject
{
public:
    ~Player() override
    {
        std::cout  << ++count << " Player 소멸\n";
    }
    // 파생 클래스에서 자신을 복제하여 반환.
    GameObject* Clone() const override
    //std::unique_ptr<GameObject> Clone() const override
    {
        return new Player(*this);
    }
};

int main()
{
	std::unique_ptr<GameObject> original = std::make_unique<Player>();
	std::unique_ptr<GameObject> copied  = std::unique_ptr<GameObject>(original->Clone());

    //std::unique_ptr<GameObject> copied = original->Clone();
}
