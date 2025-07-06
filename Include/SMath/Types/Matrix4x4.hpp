#pragma once

#include <stdexcept>
#include <array>

namespace smath {
    struct Matrix4x4 {
        std::array<std::array<float, 4>, 4> Data;

        inline constexpr Matrix4x4(float _Scalar = 1) noexcept;
        inline constexpr Matrix4x4(const std::array<std::array<float, 4>, 4>& _Data) noexcept;
        inline constexpr Matrix4x4(const Matrix4x4& _Other) noexcept;

        inline constexpr Matrix4x4 operator+(const Matrix4x4& _Other) const noexcept;
        inline constexpr Matrix4x4 operator-(const Matrix4x4& _Other) const noexcept;
        inline constexpr Matrix4x4 operator*(const Matrix4x4& _Other) const noexcept;
        inline constexpr Matrix4x4 operator*(float _Scalar) const noexcept;
        inline Matrix4x4 operator/(float _Scalar) const;

        inline constexpr Matrix4x4& operator+=(const Matrix4x4& _Other) noexcept;
        inline constexpr Matrix4x4& operator-=(const Matrix4x4& _Other) noexcept;
        inline constexpr Matrix4x4& operator*=(const Matrix4x4& _Other) noexcept;
        inline constexpr Matrix4x4& operator*=(float _Scalar) noexcept;
        inline Matrix4x4& operator/=(float _Scalar);

        inline constexpr bool operator==(const Matrix4x4& _Other) const noexcept;
        inline constexpr bool operator!=(const Matrix4x4& _Other) const noexcept;

        inline float& operator()(size_t _Row, size_t _Col);
        inline const float& operator()(size_t _Row, size_t _Col) const;
    };

    using Mat4 = Matrix4x4;

} // namespace smath

#include "Matrix4x4_impl.hpp"