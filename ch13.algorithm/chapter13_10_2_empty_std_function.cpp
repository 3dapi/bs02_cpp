#include <functional>
#include <iostream>

int main()
{
    std::function<void()> callback;

    if (!callback)
    {
        std::cout << "empty callback\n";
    }

    try
    {
        callback();
    }
    catch (const std::bad_function_call&)
    {
        std::cout << "bad function call\n";
    }
}
