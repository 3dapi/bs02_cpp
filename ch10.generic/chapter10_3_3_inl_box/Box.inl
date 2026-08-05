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
