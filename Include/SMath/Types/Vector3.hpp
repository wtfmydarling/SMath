#pragma once

#include <stdexcept>

namespace smath {
    struct Vector2;
    struct Vector4;

    struct Vector3 {
	    float x, y, z;

        inline constexpr Vector3(float _x = 0, float _y = 0, float _z = 0) noexcept;
        inline constexpr Vector3(const Vector2& _Other, float _z) noexcept;
        inline constexpr Vector3(const Vector3& _Other) noexcept;
        inline constexpr Vector3(const Vector4& _Other) noexcept;

	    inline constexpr Vector3 operator+(const Vector3& _Other) const noexcept;
        inline constexpr Vector3 operator-(const Vector3& _Other) const noexcept;
        inline constexpr Vector3 operator*(float _Scalar) const noexcept;
        inline Vector3 operator/(float _Scalar) const;

        inline constexpr Vector3& operator+=(const Vector3& _Other) noexcept;
        inline constexpr Vector3& operator-=(const Vector3& _Other) noexcept;
        inline constexpr Vector3& operator*=(float _Scalar) noexcept;
        inline Vector3& operator/=(float _Scalar);

        inline constexpr bool operator==(const Vector3& _Other) const noexcept;
        inline constexpr bool operator!=(const Vector3& _Other) const noexcept;
    };

    using Vec3 = Vector3;

} // namespace smath

#include "Vector3_impl.hpp"