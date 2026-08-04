#include <iostream>


enum class Permission : unsigned int
{
    None    = 0,
    Read    = 1u << 0,
    Write   = 1u << 1,
    Execute = 1u << 2,
    All     = (1u << 0) | (1u << 1) | (1u << 2)
};

constexpr Permission operator|(Permission left, Permission right)
{
    return static_cast<Permission>(
        static_cast<unsigned int>(left) |
        static_cast<unsigned int>(right));
}

constexpr Permission operator&(Permission left, Permission right)
{
    return static_cast<Permission>(
        static_cast<unsigned int>(left) &
        static_cast<unsigned int>(right));
}

constexpr bool HasPermission(Permission value, Permission flag)
{
    return (value & flag) == flag;
}

int main()
{
    Permission permissions =
        Permission::Read | Permission::Write;

    if (HasPermission(permissions, Permission::Write))
    {
        std::cout << "writable\n";
    }
}
