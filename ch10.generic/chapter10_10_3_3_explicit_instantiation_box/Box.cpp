#include "Box.h"

#include <string>

template <typename T>
Box<T>::Box(const T& value)
    : value(value)
{
}

template <typename T>
const T& Box<T>::GetValue() const
{
    return value;
}

template class Box<int>;
template class Box<double>;
template class Box<std::string>;
