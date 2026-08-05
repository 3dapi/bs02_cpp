#include <iostream>
#include <string>
#include <thread>

class Loader
{
public:
    void Load(std::string fileName)
    {
        std::cout << fileName << '\n';
    }
};

int main()
{
    Loader loader;
    std::thread worker{&Loader::Load, &loader, "data.bin"};
    worker.join();
}
