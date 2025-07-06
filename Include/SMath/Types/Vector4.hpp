#pragma once

#include <stdexcept>

namespace smath {
    struct Vector2;
    struct Vector3;

    struct Vector4 {
	    float x, y, z, w;

        inline constexpr Vector4(float _x = 0, float _y = 0, float _z = 0, float _w = 1) noexcept;
        inline constexpr Vector4(const Vector2& _Other, float _z, float _w) noexcept;
        inline constexpr Vector4(const Vector3& _Other, float _w) noexcept;
        inline constexpr Vector4(const Vector4& _Other) noexcept;

        inline constexpr Vector4 operator+(const Vector4& _Other) const noexcept;
        inline constexpr Vector4 operator-(const Vector4& _Other) const noexcept;
        inline constexpr Vector4 operator*(float _Scalar) const noexcept;
        inline Vector4 operator/(float _Scalar) const;

        inline constexpr Vector4& operator+=(const Vector4& _Other) noexcept;
        inline constexpr Vector4& operator-=(const Vector4& _Other) noexcept;
        inline constexpr Vector4& operator*=(float _Scalar) noexcept;
        inline Vector4& operator/=(float _Scalar);

        inline constexpr bool operator==(const Vector4& _Other) const noexcept;
        inline constexpr bool operator!=(const Vector4& _Other) const noexcept;
    };

    using Vec4 = Vector4;

} // namespace smath

#include "Vector4_impl.hpp"