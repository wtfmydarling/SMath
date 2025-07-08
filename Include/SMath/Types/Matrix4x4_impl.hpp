#pragma once

#include "Matrix4x4.hpp"

namespace smath {
    inline constexpr Matrix4x4::Matrix4x4(float _Scalar) noexcept 
        : Data({_Scalar, 0, 0, 0, 0, _Scalar, 0, 0, 0, 0, _Scalar, 0, 0, 0, 0, _Scalar}) {
    }

    inline constexpr Matrix4x4::Matrix4x4(const std::array<std::array<float, 4>, 4>& _Data) noexcept
        : Data(_Data) {
    }

    inline constexpr Matrix4x4::Matrix4x4(const Matrix4x4& _Other) noexcept 
        : Data(_Other.Data) {
    }

    inline constexpr Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _Other) const noexcept {
        Matrix4x4 Result;
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Result.Data[i][j] = Data[i][j] + _Other.Data[i][j];
            }
        }

        return Result;
    }

    inline constexpr Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _Other) const noexcept {
        Matrix4x4 Result;
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Result.Data[i][j] = Data[i][j] - _Other.Data[i][j];
            }
        }

        return Result;
    }

    inline constexpr Matrix4x4 Matrix4x4::operator*(const Matrix4x4& _Other) const noexcept {
        Matrix4x4 Result(0.0f);
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                for (size_t k = 0; k < 4; k++) {
                    Result.Data[i][j] += Data[i][k] * _Other.Data[k][j];
                }
            }
        }

        return Result;
    }

    inline constexpr Matrix4x4 Matrix4x4::operator*(float _Scalar) const noexcept {
        Matrix4x4 Result;
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Result.Data[i][j] = Data[i][j] * _Scalar;
            }
        }

        return Result;
    }

    inline Matrix4x4 Matrix4x4::operator/(float _Scalar) const {
        if (_Scalar == 0) {
            throw std::runtime_error("Division by zero in Matrix4x4 operator/");
        }

        Matrix4x4 Result;
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Result.Data[i][j] = Data[i][j] / _Scalar;
            }
        }

        return Result;
    }

    inline constexpr Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& _Other) noexcept {
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Data[i][j] += _Other.Data[i][j];
            }
        }
        return *this;
    }

    inline constexpr Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& _Other) noexcept {
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Data[i][j] -= _Other.Data[i][j];
            }
        }

        return *this;
    }

    inline constexpr Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& _Other) noexcept {
        Matrix4x4 Result(0.0f);
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                for (size_t k = 0; k < 4; k++) {
                    Result.Data[i][j] += Data[i][k] * _Other.Data[k][j];
                }
            }
        }
        *this = Result;

        return *this;
    }

    inline constexpr Matrix4x4& Matrix4x4::operator*=(float _Scalar) noexcept {
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Data[i][j] *= _Scalar;
            }
        }

        return *this;
    }

    inline Matrix4x4& Matrix4x4::operator/=(float _Scalar) {
        if (_Scalar == 0) {
            throw std::runtime_error("Division by zero in Matrix4x4 operator/=");
        }

        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                Data[i][j] /= _Scalar;
            }
        }

        return *this;
    }

    inline constexpr bool Matrix4x4::operator==(const Matrix4x4& _Other) const noexcept {
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                if (Data[i][j] != _Other.Data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    inline constexpr bool Matrix4x4::operator!=(const Matrix4x4& _Other) const noexcept {
        return !(*this == _Other);
    }

    inline float& Matrix4x4::operator()(size_t _Row, size_t _Col) {
        if (_Row >= 4 || _Col >= 4) {
            throw std::out_of_range("Matrix4x4 index out of range");
        }

        return Data[_Row][_Col];
    }

    inline const float& Matrix4x4::operator()(size_t _Row, size_t _Col) const {
        if (_Row >= 4 || _Col >= 4) {
            throw std::out_of_range("Matrix4x4 index out of range");
        }

        return Data[_Row][_Col];
    }

    } // namespace smath