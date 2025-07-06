#pragma once

#include <stdexcept>

namespace smath {

    struct Vector3;

    struct Quaternion {
	    float w, x, y, z;

        inline constexpr Quaternion(float _w = 1, float _x = 0, float _y = 0, float _z = 0) noexcept;
        inline constexpr Quaternion(float _w, const Vector3& _Vector) noexcept;
        inline constexpr Quaternion(const Quaternion& _Other) noexcept;

        inline constexpr Quaternion operator+(const Quaternion& _Other) const noexcept;
        inline constexpr Quaternion operator-(const Quaternion& _Other) const noexcept;
        inline constexpr Quaternion operator*(const Quaternion& _Other) const noexcept;
        inline Quaternion operator/(const Quaternion& _Other) const;
        inline constexpr Quaternion operator*(float _Scalar) const noexcept;
        inline Quaternion operator/(float _Scalar) const;

        inline constexpr Quaternion& operator+=(const Quaternion& _Other) noexcept;
        inline constexpr Quaternion& operator-=(const Quaternion& _Other) noexcept;
        inline constexpr Quaternion& operator*=(const Quaternion& _Other) noexcept;
        inline Quaternion& operator/=(const Quaternion& _Other);
        inline constexpr Quaternion& operator*=(float _Scalar) noexcept;
        inline Quaternion& operator/=(float _Scalar);

        inline constexpr bool operator==(const Quaternion& _Other) const noexcept;
        inline constexpr bool operator!=(const Quaternion& _Other) const noexcept;
    };

    using Quat = Quaternion;

} // namespace smath

#include "Quaternion_impl.hpp"