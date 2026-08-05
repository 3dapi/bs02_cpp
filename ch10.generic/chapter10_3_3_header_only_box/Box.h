#pragma once

template <typename T>
class Box
{
public:
    explicit Box(const T& value)
        : value(value)
    {
    }

    const T& GetValue() const
    {
        return value;
    }

private:
    T value;
};
