#pragma once

#include "Matrix3x3.hpp"

namespace smath {
    inline constexpr Matrix3x3::Matrix3x3(float _Scalar) noexcept
        : Data({_Scalar, 0, 0, 0, _Scalar, 0, 0, 0, _Scalar}) {
    }

    inline constexpr Matrix3x3::Matrix3x3(const std::array<std::array<float, 3>, 3>& _Data) noexcept
        : Data(_Data) {
    }

    inline constexpr Matrix3x3::Matrix3x3(const Matrix3x3& _Other) noexcept : Data(_Other.Data) {
    }

    inline constexpr Matrix3x3 Matrix3x3::operator+(const Matrix3x3& _Other) const noexcept {
        Matrix3x3 Result;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Result.Data[i][j] = Data[i][j] + _Other.Data[i][j];
            }
        }

        return Result;
    }

    inline constexpr Matrix3x3 Matrix3x3::operator-(const Matrix3x3& _Other) const noexcept {
        Matrix3x3 Result;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Result.Data[i][j] = Data[i][j] - _Other.Data[i][j];
            }
        }

        return Result;
    }

    inline constexpr Matrix3x3 Matrix3x3::operator*(const Matrix3x3& _Other) const noexcept {
        Matrix3x3 Result(0.0f);
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                for (size_t k = 0; k < 3; k++) {
                    Result.Data[i][j] += Data[i][k] * _Other.Data[k][j];
                }
            }
        }

        return Result;
    }

    inline constexpr Matrix3x3 Matrix3x3::operator*(float _Scalar) const noexcept {
        Matrix3x3 Result;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Result.Data[i][j] = Data[i][j] * _Scalar;
            }
        }

        return Result;
    }

    inline Matrix3x3 Matrix3x3::operator/(float _Scalar) const {
        if (_Scalar == 0) {
            throw std::runtime_error("Division by zero in Matrix3x3 operator/");
        }

        Matrix3x3 Result;
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Result.Data[i][j] = Data[i][j] / _Scalar;
            }
        }

        return Result;
    }

    inline constexpr Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& _Other) noexcept {
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Data[i][j] += _Other.Data[i][j];
            }
        }
        return *this;
    }

    inline constexpr Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& _Other) noexcept {
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Data[i][j] -= _Other.Data[i][j];
            }
        }

        return *this;
    }

    inline constexpr Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& _Other) noexcept {
        Matrix3x3 Result(0.0f);
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                for (size_t k = 0; k < 4; k++) {
                    Result.Data[i][j] += Data[i][k] * _Other.Data[k][j];
                }
            }
        }
        *this = Result;

        return *this;
    }

    inline constexpr Matrix3x3& Matrix3x3::operator*=(float _Scalar) noexcept {
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Data[i][j] *= _Scalar;
            }
        }

        return *this;
    }

    inline Matrix3x3& Matrix3x3::operator/=(float _Scalar) {
        if (_Scalar == 0) {
            throw std::runtime_error("Division by zero in Matrix3x3 operator/=");
        }

        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                Data[i][j] /= _Scalar;
            }
        }

        return *this;
    }

    inline constexpr bool Matrix3x3::operator==(const Matrix3x3& _Other) const noexcept {
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                if (Data[i][j] != _Other.Data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    inline constexpr bool Matrix3x3::operator!=(const Matrix3x3& _Other) const noexcept {
        return !(*this == _Other);
    }

    inline float& Matrix3x3::operator()(size_t _Row, size_t _Col) {
        if (_Row >= 3 || _Col >= 3) {
            throw std::out_of_range("Matrix3x3 index out of range");
        }

        return Data[_Row][_Col];
    }

    inline const float& Matrix3x3::operator()(size_t _Row, size_t _Col) const {
        if (_Row >= 3 || _Col >= 3) {
            throw std::out_of_range("Matrix3x3 index out of range");
        }

        return Data[_Row][_Col];
    }

    } // namespace smath