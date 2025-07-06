#pragma once

#include "Vector3.hpp"

#include "Vector2.hpp"
#include "Vector4.hpp"

namespace smath {
    inline constexpr Vector3::Vector3(float _x, float _y, float _z) noexcept 
        : x(_x), y(_y), z(_z) {}

    inline constexpr Vector3::Vector3(const Vector2& _Other, float _z) noexcept 
        : x(_Other.x), y(_Other.y), z(_z) {}

    inline constexpr Vector3::Vector3(const Vector3& _Other) noexcept
        : x(_Other.x), y(_Other.y), z(_Other.z) {}

    inline constexpr Vector3::Vector3(const Vector4& _Other) noexcept
        : x(_Other.x), y(_Other.y), z(_Other.z) {}

    inline constexpr Vector3 Vector3::operator+(const Vector3& _Other) const noexcept {
        return Vector3(x + _Other.x, y + _Other.y, z + _Other.z);
    }

    inline constexpr Vector3 Vector3::operator-(const Vector3& _Other) const noexcept {
        return Vector3(x - _Other.x, y - _Other.y, z - _Other.z);
    }

    inline constexpr Vector3 Vector3::operator*(float _Scalar) const noexcept {
        return Vector3(x * _Scalar, y * _Scalar, z * _Scalar);
    }

    inline Vector3 Vector3::operator/(float _Scalar) const {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector3 division.");
        }

        return Vector3(x / _Scalar, y / _Scalar, z / _Scalar);
    }

    inline constexpr Vector3& Vector3::operator+=(const Vector3& _Other) noexcept {
        x += _Other.x;
        y += _Other.y;
        z += _Other.z;

        return *this;
    }

    inline constexpr Vector3& Vector3::operator-=(const Vector3& _Other) noexcept {
        x -= _Other.x;
        y -= _Other.y;
        z -= _Other.z;

        return *this;
    }

    inline constexpr Vector3& Vector3::operator*=(float _Scalar) noexcept {
        x *= _Scalar;
        y *= _Scalar;
        z *= _Scalar;

        return *this;
    }

    inline Vector3& Vector3::operator/=(float _Scalar) {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector3 division.");
        }

        x /= _Scalar;
        y /= _Scalar;
        z /= _Scalar;

        return *this;
    }

    inline constexpr bool Vector3::operator==(const Vector3& _Other) const noexcept {
        return x == _Other.x && y == _Other.y && z == _Other.z;
    }

    inline constexpr bool Vector3::operator!=(const Vector3& _Other) const noexcept {
        return !(*this == _Other);
    }

} // namespace smath
