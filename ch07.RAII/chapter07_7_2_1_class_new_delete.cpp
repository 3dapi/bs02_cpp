#include <iostream>

class Resource
{
public:
    explicit Resource(int id)
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
    Resource* resource = new Resource(1);

    delete resource;
    resource = nullptr;

    delete resource;
}
