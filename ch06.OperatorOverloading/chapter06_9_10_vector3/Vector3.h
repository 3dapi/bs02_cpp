#pragma once
#include <cstddef>
#include <iosfwd>

class Vector3
{
public:
    static constexpr float EPSILON = 0.0001f;
public:
    Vector3() = default;
    Vector3(float x, float y, float z) : values{x, y, z} { }
    float GetX() const;
    float GetY() const;
    float GetZ() const;

    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3& operator*=(float scalar);
    Vector3 operator+() const;
    Vector3 operator-() const;

    bool operator==(const Vector3& rhs) const;
    bool NearlyEquals(const Vector3& rhs, float epsilon=EPSILON) const;

    float& operator[](std::size_t index);
    const float& operator[](std::size_t index) const;

    float& At(std::size_t index);
    const float& At(std::size_t index) const;

public:
    float values[3] = {};
    friend std::istream& operator>>(std::istream& input, Vector3& vec3);
};

Vector3 operator+(Vector3 left, const Vector3& right);
Vector3 operator-(Vector3 left, const Vector3& right);
Vector3 operator*(Vector3 vec3, float scalar);
Vector3 operator*(float scalar, Vector3 vec3);

std::ostream& operator<<(std::ostream& output, const Vector3& vec3);
std::istream& operator>>(std::istream& input, Vector3& vec3);
