#pragma once

#include "Vector4.hpp"

#include "Vector2.hpp"
#include "Vector3.hpp"

namespace smath {
    inline constexpr Vector4::Vector4(float _x, float _y, float _z, float _w) noexcept 
        : x(_x), y(_y), z(_z), w(_w){
    }

    inline constexpr Vector4::Vector4(const Vector2& _Other, float _z, float _w) noexcept
        : x(_Other.x), y(_Other.y), z(_z), w(_w) {
    }

    inline constexpr Vector4::Vector4(const Vector3& _Other, float _w) noexcept
        : x(_Other.x), y(_Other.y), z(_Other.z), w(_w) {
    }

    inline constexpr Vector4::Vector4(const Vector4& _Other) noexcept 
        : x(_Other.x), y(_Other.y), z(_Other.z), w(_Other.w) {
    }

    inline constexpr Vector4 Vector4::operator+(const Vector4& _Other) const noexcept {
        return Vector4(x + _Other.x, y + _Other.y, z + _Other.z, w + _Other.w);
    }

    inline constexpr Vector4 Vector4::operator-(const Vector4& _Other) const noexcept {
        return Vector4(x - _Other.x, y - _Other.y, z - _Other.z, w - _Other.w);
    }

    inline constexpr Vector4 Vector4::operator*(float _Scalar) const noexcept {
        return Vector4(x * _Scalar, y * _Scalar, z * _Scalar, w * _Scalar);
    }

    inline Vector4 Vector4::operator/(float _Scalar) const {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector4 division.");
        }

        return Vector4(x / _Scalar, y / _Scalar, z / _Scalar, w / _Scalar);
    }

    inline constexpr Vector4& Vector4::operator+=(const Vector4& _Other) noexcept {
        x += _Other.x;
        y += _Other.y;
        z += _Other.z;
        w += _Other.w;

        return *this;
    }

    inline constexpr Vector4& Vector4::operator-=(const Vector4& _Other) noexcept {
        x -= _Other.x;
        y -= _Other.y;
        z -= _Other.z;
        w -= _Other.w;

        return *this;
    }

    inline constexpr Vector4& Vector4::operator*=(float _Scalar) noexcept {
        x *= _Scalar;
        y *= _Scalar;
        z *= _Scalar;
        w *= _Scalar;

        return *this;
    }

    inline Vector4& Vector4::operator/=(float _Scalar) {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector4 division.");
        }

        x /= _Scalar;
        y /= _Scalar;
        z /= _Scalar;
        w /= _Scalar;

        return *this;
    }

    inline constexpr bool Vector4::operator==(const Vector4& _Other) const noexcept {
        return x == _Other.x && y == _Other.y && z == _Other.z && w == _Other.w;
    }

    inline constexpr bool Vector4::operator!=(const Vector4& _Other) const noexcept {
        return !(*this == _Other);
    }

} // namespace smath