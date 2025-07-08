#pragma once

#include <stdexcept>
#include <array>

namespace smath {
    struct Matrix3x3 {
        std::array<std::array<float, 3>, 3> Data;

        inline constexpr Matrix3x3(float _Scalar = 1) noexcept;
        inline constexpr Matrix3x3(const std::array<std::array<float, 3>, 3>& _Data) noexcept;
        inline constexpr Matrix3x3(const Matrix3x3& _Other) noexcept;

        inline constexpr Matrix3x3 operator+(const Matrix3x3& _Other) const noexcept;
        inline constexpr Matrix3x3 operator-(const Matrix3x3& _Other) const noexcept;
        inline constexpr Matrix3x3 operator*(const Matrix3x3& _Other) const noexcept;
        inline constexpr Matrix3x3 operator*(float _Scalar) const noexcept;
        inline Matrix3x3 operator/(float _Scalar) const;

        inline constexpr Matrix3x3& operator+=(const Matrix3x3& _Other) noexcept;
        inline constexpr Matrix3x3& operator-=(const Matrix3x3& _Other) noexcept;
        inline constexpr Matrix3x3& operator*=(const Matrix3x3& _Other) noexcept;
        inline constexpr Matrix3x3& operator*=(float _Scalar) noexcept;
        inline Matrix3x3& operator/=(float _Scalar);

        inline constexpr bool operator==(const Matrix3x3& _Other) const noexcept;
        inline constexpr bool operator!=(const Matrix3x3& _Other) const noexcept;

        inline float& operator()(size_t _Row, size_t _Col);
        inline const float& operator()(size_t _Row, size_t _Col) const;
    };

    using Mat3 = Matrix3x3;

} // namespace smath

#include "Matrix3x3_impl.hpp"