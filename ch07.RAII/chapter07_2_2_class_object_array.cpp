#include <iostream>

class Resource
{
public:
    explicit Resource(int id = 0)
        : id(id)
    {
        std::cout << "Resource "
                  << id << " 생성\n";
    }

    ~Resource()
    {
        std::cout << "Resource "
                  << id << " 소멸\n";
    }

private:
    int id;
};

int main()
{
    Resource* resources = new Resource[3]
    {
        Resource(1),
        Resource(2),
        Resource(3)
    };

    delete[] resources;
}
