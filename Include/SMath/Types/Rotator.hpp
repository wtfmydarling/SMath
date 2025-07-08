#pragma once

#include <stdexcept>

namespace smath {
    struct Vector3;

    struct Rotator {
        float Pitch, Yaw, Roll;

        inline constexpr Rotator(float _Pitch = 0, float _Yaw = 0, float _Roll = 0) noexcept;
        inline constexpr Rotator(const Rotator& _Rot) noexcept;

        inline constexpr Rotator operator+(const Rotator& _Other) const noexcept;
        inline constexpr Rotator operator-(const Rotator& _Other) const noexcept;
        inline constexpr Rotator operator*(float _Scalar) const noexcept;
        inline Rotator operator/(float _Scalar) const;

        inline constexpr Rotator& operator+=(const Rotator& _Other) noexcept;
        inline constexpr Rotator& operator-=(const Rotator& _Other) noexcept;
        inline constexpr Rotator& operator*=(float _Scalar) noexcept;
        inline Rotator& operator/=(float _Scalar);

        inline constexpr bool operator==(const Rotator& _Other) const noexcept;
        inline constexpr bool operator!=(const Rotator& _Other) const noexcept;
    };

    using Rot = Rotator;

} // namespace smath

#include "Rotator_impl.hpp"