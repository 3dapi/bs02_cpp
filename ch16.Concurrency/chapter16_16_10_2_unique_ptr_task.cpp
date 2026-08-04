#include <iostream>
#include <memory>
#include <thread>

struct Resource
{
    int value;
};

void Process(std::unique_ptr<Resource> resource, int& result)
{
    result = resource->value;
}

int main()
{
    auto resource = std::make_unique<Resource>(Resource{42});
    int result = 0;

    std::jthread worker{
        Process,
        std::move(resource),
        std::ref(result)};

    worker.join();

    std::cout << std::boolalpha
              << (resource == nullptr) << ' '
              << result << '\n';
}
