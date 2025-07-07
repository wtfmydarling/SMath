#pragma once

#include "SMath.hpp"

namespace smath {

    inline float Sqrt(float _Value) noexcept {
        return std::sqrtf(_Value);
    }

    inline constexpr float ToRadians(float _Degrees) noexcept {
        return _Degrees * (Pi / 180.0f);
    }

    inline constexpr float ToDegrees(float _Radians) noexcept {
        return _Radians * (180.0f / Pi);
    }

    inline float Sin(float _Angle) noexcept {
        return std::sinf(_Angle);
    }

    inline float SinDegrees(float _Angle) noexcept {
        return std::sinf(ToRadians(_Angle));
    }

    inline float Cos(float _Angle) noexcept {
        return std::cosf(_Angle);
    }

    inline float CosDegrees(float _Angle) noexcept {
        return std::cosf(ToRadians(_Angle));
    }

    inline float Tan(float _Angle) noexcept {
        return std::tan(_Angle);
    }

    inline float TanDegrees(float _Angle) noexcept {
        return std::tan(ToRadians(_Angle));
    }

    inline float ASin(float _Value) noexcept {
        return std::asinf(_Value);
    }

    inline float ASinDegrees(float _Value) noexcept {
        return ToDegrees(std::asinf(_Value));
    }

    inline float ACos(float _Value) noexcept {
        return std::acosf(_Value);
    }

    inline float ACosDegrees(float _Value) noexcept {
        return ToDegrees(std::acosf(_Value));
    }

    inline float ATan(float _Value) noexcept {
        return std::atanf(_Value);
    }

    inline float ATanDegrees(float _Value) noexcept {
        return ToDegrees(std::atanf(_Value));
    }

    inline float ATan2(float _Y, float _X) noexcept {
        return std::atan2f(_Y, _X);
    }

    inline float ATan2Degrees(float _Y, float _X) noexcept {
        return ToDegrees(std::atan2f(_Y, _X));
    }

    inline float ClampAngle(float _Angle) noexcept {
        float Turns = std::floor(_Angle / 360.0f);
        return _Angle - Turns * 360.0f;
    }

    inline float ClampAngle180(float _Angle) noexcept {
        _Angle = ClampAngle(_Angle);
        if (_Angle > 180.0f) {
            _Angle -= 360.0f;
        }
        return _Angle;
    }

    inline constexpr float Clamp(float _In, float _Min, float _Max) noexcept {
        return std::min(std::max(_In, _Min), _Max);
    }

    inline float Distance(const Vector2& _A, const Vector2& _B) noexcept {
        return Sqrt((_B.x - _A.x) * (_B.x - _A.x) + (_B.y - _A.y) * (_B.y - _A.y));
    }

    inline float Distance(const Vector3& _A, const Vector3& _B) noexcept {
        return Sqrt((_B.x - _A.x) * (_B.x - _A.x) + (_B.y - _A.y) * (_B.y - _A.y) +
                    (_B.z - _A.z) * (_B.z - _A.z));
    }

    inline float Distance(const Vector4& _A, const Vector4& _B) noexcept {
        return Sqrt((_B.x - _A.x) * (_B.x - _A.x) + (_B.y - _A.y) * (_B.y - _A.y) +
                    (_B.z - _A.z) * (_B.z - _A.z) + (_B.w - _A.w) * (_B.w - _A.w));
    }

    inline constexpr float DotProduct(const Vector2& _A, const Vector2& _B) noexcept {
        return _A.x * _B.x + _A.y * _B.y;
    }

    inline constexpr float DotProduct(const Vector3& _A, const Vector3& _B) noexcept {
        return _A.x * _B.x + _A.y * _B.y + _A.z * _B.z;
    }

    inline constexpr float DotProduct(const Vector4& _A, const Vector4& _B) noexcept {
        return _A.x * _B.x + _A.y * _B.y + _A.z * _B.z + _A.w * _B.w;
    }

    inline constexpr Vector3 CrossProduct(const Vector3& _A, const Vector3& _B) noexcept {
        return Vector3(_A.y * _B.z - _A.z * _B.y, _A.z * _B.x - _A.x * _B.z, _A.x * _B.y - _A.y * _B.x);
    }

    inline float Length(const Vector2& _Vec) noexcept {
        return Sqrt(_Vec.x * _Vec.x + _Vec.y * _Vec.y);
    }

    inline float Length(const Vector3& _Vec) noexcept {
        return Sqrt(_Vec.x * _Vec.x + _Vec.y * _Vec.y + _Vec.z * _Vec.z);
    }

    inline float Length(const Vector4& _Vec) noexcept {
        return Sqrt(_Vec.x * _Vec.x + _Vec.y * _Vec.y + _Vec.z * _Vec.z + _Vec.w * _Vec.w);
    }

    inline Vector2 Normalize(const Vector2& _Vec) {
        return _Vec / Length(_Vec);
    }

    inline Vector3 Normalize(const Vector3& _Vec) {
        return _Vec / Length(_Vec);
    }

    inline Vector4 Normalize(const Vector4& _Vec) {
        return _Vec / Length(_Vec);
    }
    // CHANGE FUNCTIONS 
    //inline Vector2 GetForwardVector(const Vector2& _Vec) {
    //    return Normalize(_Vec);
    //}

    //inline Vector3 GetForwardVector(const Vector3& _Vec) {
    //    return Normalize(_Vec);
    //}

    //inline Vector4 GetForwardVector(const Vector4& _Vec) {
    //    return Normalize(_Vec);
    //}

    //inline Vector3 GetRightVector(const Vector3& _Vec) {
    //    float Yaw = std::atan2(_Vec.x, _Vec.z);
    //    return Vector3(std::cos(Yaw), 0.0f, -std::sin(Yaw));
    //}

    //inline Vector3 GetUpVector(const Vector3& _Vec) {
    //    return CrossProduct(GetForwardVector(_Vec), GetRightVector(_Vec));
    //}

    inline float GetVectorYaw(const Vector3& _Vec) {
        return ATan2(Normalize(_Vec).x, Normalize(_Vec).z);
    }

    inline float GetVectorPitch(const Vector3& _Vec) {
        return ASin(Normalize(_Vec).y);
    }

    inline constexpr Vector3 GetVectorFromYawPitch(float _Yaw, float _Pitch) noexcept {
        return Vector3(Sin(_Yaw) * Cos(_Pitch), Sin(_Pitch),
                       Cos(_Yaw) * Cos(_Pitch));
    }

    inline Vector3 RotateAroundAxis(const Vector3& _Vec, const Vector3& _Axis, float _Angle) {
        Vector3 Axis = Normalize(_Axis);
        float CosAngle = Cos(_Angle);
        float SinAngle = Sin(_Angle);

        return _Vec * CosAngle + CrossProduct(Axis, _Vec) * SinAngle +
               Axis * DotProduct(Axis, _Vec) * (1.0f - CosAngle);
    }

    inline constexpr float SqrNorm(const Quaternion& _Quat) noexcept {
        return _Quat.w * _Quat.w + _Quat.x * _Quat.x + _Quat.y * _Quat.y + _Quat.z * _Quat.z;
    }

    inline float Norm(const Quaternion& _Quat) noexcept {
        return Sqrt(SqrNorm(_Quat));
    }

    inline Quaternion Normalize(const Quaternion& _Quat) {
        return _Quat / SqrNorm(_Quat);
    }

    inline constexpr Quaternion Conjugate(const Quaternion& _Quat) noexcept {
        return Quaternion(_Quat.w, -_Quat.x, -_Quat.y, -_Quat.z);
    }

    inline Quaternion Inverse(const Quaternion& _Quat) {
        return Conjugate(_Quat) / SqrNorm(_Quat);
    }

} // namespace smath