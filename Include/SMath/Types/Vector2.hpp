#pragma once

#include <stdexcept>

namespace smath{
    struct Vector3;
    struct Vector4;

    struct Vector2 {
	    float x, y;

        inline constexpr Vector2(float _x = 0, float _y = 0) noexcept;
        inline constexpr Vector2(const Vector2& _Other) noexcept;
        inline constexpr Vector2(const Vector3& _Other) noexcept;
        inline constexpr Vector2(const Vector4& _Other) noexcept;

        inline constexpr Vector2 operator+(const Vector2& _Other) const noexcept;
        inline constexpr Vector2 operator-(const Vector2& _Other) const noexcept;
        inline constexpr Vector2 operator*(float _Scalar) const noexcept;
        inline Vector2 operator/(float _Scalar) const;

        inline constexpr Vector2& operator+=(const Vector2& _Other) noexcept;
        inline constexpr Vector2& operator-=(const Vector2& _Other) noexcept;
        inline constexpr Vector2& operator*=(float _Scalar) noexcept;
        inline Vector2& operator/=(float _Scalar);

        inline constexpr bool operator==(const Vector2& _Other) const noexcept;
        inline constexpr bool operator!=(const Vector2& _Other) const noexcept;
    };

    using Vec2 = Vector2;

} // namespace smath

#include "Vector2_impl.hpp"