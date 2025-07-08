#pragma once

#include "Rotator.hpp"

namespace smath {

	inline constexpr Rotator::Rotator(float _Pitch, float _Yaw, float _Roll) noexcept
		: Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll) {
	}

	inline constexpr Rotator::Rotator(const Rotator& _Rot) noexcept
		: Pitch(_Rot.Pitch), Yaw(_Rot.Yaw), Roll(_Rot.Roll) {
    }

    inline constexpr Rotator Rotator::operator+(const Rotator& _Other) const noexcept {
        return Rotator(Pitch + _Other.Pitch, Yaw + _Other.Yaw, Roll + _Other.Roll);
    }

	inline constexpr Rotator Rotator::operator-(const Rotator& _Other) const noexcept {
        return Rotator(Pitch - _Other.Pitch, Yaw - _Other.Yaw, Roll - _Other.Roll);
    }

    inline constexpr Rotator Rotator::operator*(float _Scalar) const noexcept {
        return Rotator(Pitch * _Scalar, Yaw * _Scalar, Roll * _Scalar);
    }

    inline Rotator Rotator::operator/(float _Scalar) const {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Rotator division.");
        }

        return Rotator(Pitch * _Scalar, Yaw * _Scalar, Roll * _Scalar);
    }

    inline constexpr Rotator& Rotator::operator+=(const Rotator& _Other) noexcept {
        Pitch   += _Other.Pitch;
        Yaw     += _Other.Yaw;
        Roll    += _Other.Roll;

        return *this;
    }

    inline constexpr Rotator& Rotator::operator-=(const Rotator& _Other) noexcept {
        Pitch   -= _Other.Pitch;
        Yaw     -= _Other.Yaw;
        Roll    -= _Other.Roll;

        return *this;
    }

    inline constexpr Rotator& Rotator::operator*=(float _Scalar) noexcept {
        Pitch   *= _Scalar;
        Yaw     *= _Scalar;
        Roll    *= _Scalar;

        return *this;
    }

    inline Rotator& Rotator::operator/=(float _Scalar) {
        if (_Scalar == 0.0f) {
            throw std::runtime_error("Division by zero in Rotator division.");
        }

        Pitch   /= _Scalar;
        Yaw     /= _Scalar;
        Roll    /= _Scalar;

        return *this;
    }

    inline constexpr bool Rotator::operator==(const Rotator& _Other) const noexcept {
        return Pitch == _Other.Pitch && Yaw == _Other.Yaw && Roll == _Other.Roll;
    }

    inline constexpr bool Rotator::operator!=(const Rotator& _Other) const noexcept {
        return !(*this == _Other);
    }

    }