#include <iostream>

class Door
{
public:
    void Open()
    {
        isOpen = true;
    }

    void Close()
    {
        isOpen = false;
    }

    bool IsOpen() const
    {
        return isOpen;
    }

private:
    bool isOpen = false;
};

int main()
{
    Door door;

    door.Open();

    if (door.IsOpen())
    {
        std::cout << "문이 열려 있습니다.\n";
    }
}
