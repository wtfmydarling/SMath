#pragma once

#include "Quaternion.hpp"

#include "Vector3.hpp"

namespace smath {
    inline constexpr Quaternion::Quaternion(float _w, float _x, float _y, float _z) noexcept
        : w(_w), x(_x), y(_y), z(_z) {
    }

    inline constexpr Quaternion::Quaternion(float _w, const Vector3& _Vector) noexcept
        : w(_w), x(_Vector.x), y(_Vector.y), z(_Vector.z) {
    }

    inline constexpr Quaternion::Quaternion(const Quaternion& _Other) noexcept
        : w(_Other.w), x(_Other.x), y(_Other.y), z(_Other.z) {
    }

    inline constexpr Quaternion Quaternion::operator+(const Quaternion& _Other) const noexcept {
        return Quaternion(w + _Other.w, x + _Other.x, y + _Other.y, z + _Other.z);
    }

    inline constexpr Quaternion Quaternion::operator-(const Quaternion& _Other) const noexcept {
        return Quaternion(w - _Other.w, x - _Other.x, y - _Other.y, z - _Other.z);
    }

    inline constexpr Quaternion Quaternion::operator*(const Quaternion& _Other) const noexcept {
        return Quaternion(w * _Other.w - x * _Other.x - y * _Other.y - z * _Other.z,
                          w * _Other.x + x * _Other.w + y * _Other.z - z * _Other.y,
                          w * _Other.y - x * _Other.z + y * _Other.w + z * _Other.x,
                          w * _Other.z + x * _Other.y - y * _Other.x + z * _Other.w);
    }

    inline Quaternion Quaternion::operator/(const Quaternion& _Other) const {
        float Norm =
            _Other.w * _Other.w + _Other.x * _Other.x + _Other.y * _Other.y + _Other.z * _Other.z;
        if (Norm == 0.0f) {
            throw std::runtime_error("Division by zero in Quaternion division.");
        }

        Quaternion Conjugate(_Other.w, -_Other.x, -_Other.y, -_Other.z);

        return (*this * Conjugate) / Norm;
    }

    inline constexpr Quaternion Quaternion::operator*(float _Scalar) const noexcept {
        return Quaternion(w * _Scalar, x * _Scalar, y * _Scalar, z * _Scalar);
    }

    inline Quaternion Quaternion::operator/(float _Scalar) const {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Quaternion division.");
        }

        return Quaternion(w / _Scalar, x / _Scalar, y / _Scalar, z / _Scalar);
    }

    inline constexpr Quaternion& Quaternion::operator+=(const Quaternion& _Other) noexcept {
        w += _Other.w;
        x += _Other.x;
        y += _Other.y;
        z += _Other.z;

        return *this;
    }

    inline constexpr Quaternion& Quaternion::operator-=(const Quaternion& _Other) noexcept {
        w -= _Other.w;
        x -= _Other.x;
        y -= _Other.y;
        z -= _Other.z;

        return *this;
    }

    inline constexpr Quaternion& Quaternion::operator*=(const Quaternion& _Other) noexcept {
        float NewW = w * _Other.w - x * _Other.x - y * _Other.y - z * _Other.z;
        float NewX = w * _Other.x + x * _Other.w + y * _Other.z - z * _Other.y;
        float NewY = w * _Other.y - x * _Other.z + y * _Other.w + z * _Other.x;
        float NewZ = w * _Other.z + x * _Other.y - y * _Other.x + z * _Other.w;
        w = NewW;
        x = NewX;
        y = NewY;
        z = NewZ;

        return *this;
    }

    inline Quaternion& Quaternion::operator/=(const Quaternion& _Other) {
        float Norm =
            _Other.w * _Other.w + _Other.x * _Other.x + _Other.y * _Other.y + _Other.z * _Other.z;
        if (Norm == 0.0f) {
            throw std::invalid_argument("Division by zero in Quaternion division.");
        }

        Quaternion Conjugate(_Other.w, -_Other.x, -_Other.y, -_Other.z);
        *this = (*this * Conjugate) / Norm;

        return *this;
    }

    inline constexpr Quaternion& Quaternion::operator*=(float _Scalar) noexcept {
        w *= _Scalar;
        x *= _Scalar;
        y *= _Scalar;
        z *= _Scalar;

        return *this;
    }

    inline Quaternion& Quaternion::operator/=(float _Scalar) {
        if (_Scalar == 0.0f) {
            throw std::invalid_argument("Division by zero in Quaternion division.");
        }
        w /= _Scalar;
        x /= _Scalar;
        y /= _Scalar;
        z /= _Scalar;

        return *this;
    }

    inline constexpr bool Quaternion::operator==(const Quaternion& _Other) const noexcept {
        return (w == _Other.w && x == _Other.x && y == _Other.y && z == _Other.z);
    }

    inline constexpr bool Quaternion::operator!=(const Quaternion& _Other) const noexcept {
        return !(*this == _Other);
    }

	} // namespace smath