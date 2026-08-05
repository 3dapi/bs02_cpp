#include "Vector3.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

float Vector3::GetX() const
{
    return values[0];
}

float Vector3::GetY() const
{
    return values[1];
}

float Vector3::GetZ() const
{
    return values[2];
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    values[0] += rhs.values[0];
    values[1] += rhs.values[1];
    values[2] += rhs.values[2];

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    values[0] -= rhs.values[0];
    values[1] -= rhs.values[1];
    values[2] -= rhs.values[2];

    return *this;
}

Vector3& Vector3::operator*=(float scalar)
{
    values[0] *= scalar;
    values[1] *= scalar;
    values[2] *= scalar;

    return *this;
}

Vector3 Vector3::operator+() const
{
    return *this;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-values[0], -values[1], -values[2]);
}

bool Vector3::operator==(const Vector3& rhs) const
{
    return values[0] == rhs.values[0]
        && values[1] == rhs.values[1]
        && values[2] == rhs.values[2];
}

bool Vector3::NearlyEquals(const Vector3& rhs, float epsilon) const
{
    return std::fabs(values[0] - rhs.values[0]) <= epsilon
        && std::fabs(values[1] - rhs.values[1]) <= epsilon
        && std::fabs(values[2] - rhs.values[2]) <= epsilon;
}

float& Vector3::operator[](std::size_t index)
{
    return values[index];
}

float& Vector3::At(std::size_t index)
{
    if (index >= 3)
    {
        throw std::out_of_range("Vector3 index");
    }

    return values[index];
}

const float& Vector3::At(std::size_t index) const
{
    if (index >= 3)
    {
        throw std::out_of_range("Vector3 index");
    }

    return values[index];
}

Vector3 operator+(Vector3 left, const Vector3& right)
{
    left += right;
    return left;
}

Vector3 operator-(Vector3 left, const Vector3& right)
{
    left -= right;
    return left;
}

Vector3 operator*(Vector3 vec3, float scalar)
{
    vec3 *= scalar;
    return vec3;
}

Vector3 operator*(float scalar, Vector3 vec3)
{
    vec3 *= scalar;
    return vec3;
}

std::ostream& operator<<(std::ostream& output, const Vector3& vec3)
{
    output << '('
           << vec3.GetX() << ", "
           << vec3.GetY() << ", "
           << vec3.GetZ() << ')';

    return output;
}

std::istream& operator>>(std::istream& input, Vector3& vec3)
{
    float x=0.0f, y=0.0f, z=0.0f;

    if (input >> x >> y >> z)
    {
        vec3.values[0] = x;
        vec3.values[1] = y;
        vec3.values[2] = z;
    }

    return input;
}
