#include <iostream>

class Player
{
public:
    void Move()
    {
        std::cout << "Player Move\n";
    }
public:
    int hp = 100;
};

template<typename T>
class SimplePtr
{
public:
    SimplePtr(const SimplePtr&) = delete;
    SimplePtr& operator=(const SimplePtr&) = delete;

    explicit SimplePtr(T* ptr) : _ptr{ptr} { }
    ~SimplePtr()
    {
        delete _ptr;
    }
    T& operator*() const
    {
        return *_ptr;
    }
    T* operator->() const
    {
        return _ptr;
    }
public:
    T* _ptr{};
};

int main()
{
    SimplePtr<Player> player(new Player);

    player._ptr->hp = 80;
    player._ptr->Move();

    (*player).hp = 70;
    (*player).Move();

    player->hp = 60;
    player->Move();

    std::cout << player->hp << '\n';
}
