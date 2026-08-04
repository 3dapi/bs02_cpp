#pragma once

template <typename T>
class Box
{
public:
    explicit Box(const T& value);
    const T& GetValue() const;

private:
    T value;
};

#include "Box.inl"
