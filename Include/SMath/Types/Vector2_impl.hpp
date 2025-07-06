#pragma once

#include "Vector2.hpp"

#include "Vector3.hpp"
#include "Vector4.hpp"

namespace smath {
    inline constexpr Vector2::Vector2(float _x, float _y) noexcept
        : x(_x), y(_y){
    }

    inline constexpr Vector2::Vector2(const Vector2& _Other) noexcept 
        : x(_Other.x), y(_Other.y) {
    }

    inline constexpr Vector2::Vector2(const Vector3& _Other) noexcept 
        : x(_Other.x), y(_Other.y) {
    }

    inline constexpr Vector2::Vector2(const Vector4& _Other) noexcept 
        : x(_Other.x), y(_Other.y) {
    }

    inline constexpr Vector2 Vector2::operator+(const Vector2& _Other) const noexcept {
        return Vector2(x + _Other.x, y + _Other.y);
    }

    inline constexpr Vector2 Vector2::operator-(const Vector2& _Other) const noexcept {
        return Vector2(x - _Other.x, y - _Other.y);
    }

    inline constexpr Vector2 Vector2::operator*(float _Scalar) const noexcept {
        return Vector2(x * _Scalar, y * _Scalar);
    }

    inline Vector2 Vector2::operator/(float _Scalar) const {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector2 division.");
        }

        return Vector2(x / _Scalar, y / _Scalar);
    }

    inline constexpr Vector2& Vector2::operator+=(const Vector2& _Other) noexcept {
        x += _Other.x;
        y += _Other.y;

        return *this;
    }

    inline constexpr Vector2& Vector2::operator-=(const Vector2& _Other) noexcept {
        x -= _Other.x;
        y -= _Other.y;

        return *this;
    }

    inline constexpr Vector2& Vector2::operator*=(float _Scalar) noexcept {
        x *= _Scalar;
        y *= _Scalar;

        return *this;
    }

    inline Vector2& Vector2::operator/=(float _Scalar) {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Vector2 division.");
        }

        x /= _Scalar;
        y /= _Scalar;

        return *this;
    }

    inline constexpr bool Vector2::operator==(const Vector2& _Other) const noexcept {
        return x == _Other.x && y == _Other.y;
    }

    inline constexpr bool Vector2::operator!=(const Vector2& _Other) const noexcept {
        return !(*this == _Other);
    }

	} // namespace smath