#pragma once

#include <cmath>
#include <algorithm>

#include "Types/Vector2.hpp"
#include "Types/Vector3.hpp"
#include "Types/Vector4.hpp"
#include "Types/Matrix4x4.hpp"
#include "Types/Quaternion.hpp"


namespace smath {
    // @brief The value of Pi as a single-precision float.
    constexpr float Pi = 3.141592653f;

    // @brief Converts degrees to radians.
    // @param _Degrees Angle in degrees.
    // @return Corresponding angle in radians.
    inline constexpr float ToRadians(float _Degrees) noexcept;

    
    // @brief Converts radians to degrees.
    // @param _Radians Angle in radians.
    // @return Corresponding angle in degrees.
    inline constexpr float ToDegrees(float _Radians) noexcept;

    // @brief Computes the sine of an angle in radians.
    // @param _Angle Angle in radians.
    // @return Sine of the angle.
    // @note Wrapper around Sin function
    //       Uses std::sin by default. The implementation can be replaced if needed.
    inline float Sin(float _Angle) noexcept;

    // @brief Computes the sine of an angle in degrees.
    // @param _Angle Angle in degrees.
    // @return Sine of the angle.
    // @note Wrapper around Sin function
    //       Uses std::sin by default. The implementation can be replaced if needed.
    inline float SinDegrees(float _Angle) noexcept;

    // @brief Computes the cosine of an angle in radians.
    // @param _Angle Angle in radians.
    // @return Cosine of the angle.
    // @note Wrapper around Cos function
    //       Uses std::cos by default. The implementation can be replaced if needed.
    inline float Cos(float _Angle) noexcept;

    // @brief Computes the cosine of an angle in degrees.
    // @param _Angle Angle in degrees.
    // @return Cosine of the angle.
    // @note Wrapper around Cos function
    //       Uses std::cos by default. The implementation can be replaced if needed.
    inline float CosDegrees(float _Angle) noexcept;

    // @brief Computes the tangent of an angle in radians.
    // @param _Angle Angle in radians.
    // @return Tangent of the angle.
    // @note Wrapper around Tan function
    //       Uses std::tan by default. The implementation can be replaced if needed.
    inline float Tan(float _Angle) noexcept;

    // @brief Computes the tangent of an angle in degrees.
    // @param _Angle Angle in degrees.
    // @return Tangent of the angle.
    // @note Wrapper around Tan function
    //       Uses std::tan by default. The implementation can be replaced if needed.
    inline float TanDegrees(float _Angle) noexcept;

    // @brief Computes the arcsine of a value in radians.
    // @param _Value Input value in the range [-1,1].
    // @return Arcsine of the value.
    // @note Wrapper around ASin function
    //       Uses std::asin by default. The implementation can be replaced if needed.
    inline float ASin(float _Value) noexcept;

    // @brief Computes the arcsine of a value and returns the result in degrees.
    // @param _Value Input value in the range [-1,1].
    // @return Arcsine of the value.
    // @note Wrapper around ASin function
    //       Uses std::asin by default. The implementation can be replaced if needed.
    inline float ASinDegrees(float _Value) noexcept;

    // @brief Computes the arccosine of a value in radians.
    // @param _Value Input value in the range [-1,1].
    // @return Arccosine of the value.
    // @note Wrapper around ACos function
    //       Uses std::acos by default. The implementation can be replaced if needed.
    inline float ACos(float _Value) noexcept;

    // @brief Computes the arccosine of a value and returns the result in degrees.
    // @param _Value Input value in the range [-1,1].
    // @return Arccosine of the value.
    // @note Wrapper around ACos function
    //       Uses std::acos by default. The implementation can be replaced if needed.
    inline float ACosDegrees(float _Value) noexcept;

    // @brief Computes the arctangent of a value in radians.
    // @param _Value Input value.
    // @return Arctangent of the value.
    // @note Wrapper around ATan function
    //       Uses std::atan by default. The implementation can be replaced if needed.
    inline float ATan(float _Value) noexcept;

    // @brief Computes the arctangent of a value and returns the result in degrees.
    // @param _Value Input value.
    // @return Arctangent of the value.
    // @note Wrapper around ATan function
    //       Uses std::atan by default. The implementation can be replaced if needed.
    inline float ATanDegrees(float _Value) noexcept;

    // @brief Computes the two-argument arctangent of y/x in radians.
    // @param _Y Y-coordinate.
    // @param _X X-coordinate.
    // @return Angle between the positive X-axis and the point (X, Y) in radians.
    // @note Wrapper around ATan2 function
    //       Uses std::atan2 by default. The implementation can be replaced if needed.
    inline float ATan2(float _Y, float _X) noexcept;

    // @brief Computes the two-argument arctangent of y/x and returns result in degrees.
    // @param _Y Y-coordinate.
    // @param _X X-coordinate.
    // @return Angle between the positive X-axis and the point (X, Y) in degrees.
    // @note Wrapper around ATan2 function
    //       Uses std::atan2 by default. The implementation can be replaced if needed.
    inline float ATan2Degrees(float _Y, float _X) noexcept;

    // @brief Clamps an angle in degrees to the range [0, 360).
    // @param _Angle Input angle in degrees.
    // @return Wrapped angle in [0, 360).
    inline float ClampAngle(float _Angle) noexcept;

    // @brief Clamps an angle in degrees to the range [-180, 180).
    // @param _Angle Input angle in degrees.
    // @return Wrapped angle in [-180, 180).
    inline float ClampAngle180(float _Angle) noexcept;

    // @brief Clamps a value between a minimum and maximum.
    // @param _In Input value.
    // @param _Min Lower bound.
    // @param _Max Upper bound.
    // @return Clamped value.
    inline constexpr float Clamp(float _In, float _Min, float _Max) noexcept;

    // @brief Computes the Euclidean distance between two 2D points.
    // @param _A First 2D point.
    // @param _B Second 2D point.
    // @return Distance between _A and _B.
    inline float Distance(const Vector2& _A, const Vector2& _B) noexcept;

    // @brief Computes the Euclidean distance between two 3D points.
    // @param _A First 3D point.
    // @param _B Second 3D point.
    // @return Distance between _A and _B.
    inline float Distance(const Vector3& _A, const Vector3& _B) noexcept;

    // @brief Computes the Euclidean distance between two 4D points.
    // @param _A First 4D point.
    // @param _B Second 4D point.
    // @return Distance between _A and _B.
    inline float Distance(const Vector4& _A, const Vector4& _B) noexcept;

    // @brief Computes the dot product of two 2D vectors.
    // @param _A First 2D vector.
    // @param _B Second 2D vector.
    // @return Dot product value.
    inline constexpr float DotProduct(const Vector2& _A, const Vector2& _B) noexcept;

    // @brief Computes the dot product of two 3D vectors.
    // @param _A First 3D vector.
    // @param _B Second 3D vector.
    // @return Dot product value.
    inline constexpr float DotProduct(const Vector3& _A, const Vector3& _B) noexcept;

    // @brief Computes the dot product of two 4D vectors.
    // @param _A First 4D vector.
    // @param _B Second 4D vector.
    // @return Dot product value.
    inline constexpr float DotProduct(const Vector4& _A, const Vector4& _B) noexcept;

    // @brief Computes the cross product of two 3D vectors.
    // @param _A First 3D vector.
    // @param _B Second 3D vector.
    // @return Vector perpendicular to both _A and _B.
    inline constexpr Vector3 CrossProduct(const Vector3& _A, const Vector3& _B) noexcept;

    // @brief Computes the length of a 2D vector.
    // @param _Vec Input vector.
    // @return Length of vector.
    inline float Length(const Vector2& _Vec) noexcept;

    // @brief Computes the length of a 3D vector.
    // @param _Vec Input vector.
    // @return Length of vector.
    inline float Length(const Vector3& _Vec) noexcept;

    // @brief Computes the length of a 4D vector.
    // @param _Vec Input vector.
    // @return Length of vector.
    inline float Length(const Vector4& _Vec) noexcept;

    // @brief Normalizes a 2D vector.
    // @param _Vec Input vector.
    // @return Normalized vector.
    inline Vector2 Normalize(const Vector2& _Vec);

    // @brief Normalizes a 3D vector.
    // @param _Vec Input vector.
    // @return Normalized vector.
    inline Vector3 Normalize(const Vector3& _Vec);

    // @brief Normalizes a 4D vector.
    // @param _Vec Input vector.
    // @return Normalized vector.
    inline Vector4 Normalize(const Vector4& _Vec);

    // REMOVE UNUSED FUNCTIONS
    // CHANGE THEM TO ROTATOR FUNCTIONS
    //[-] inline Vector2 GetForwardVector(const Vector2& _Vec);
    //[-] inline Vector3 GetForwardVector(const Vector3& _Vec);
    //[-] inline Vector4 GetForwardVector(const Vector4& _Vec);
    //[-] inline Vector3 GetRightVector(const Vector3& _Vec);
    //[-] inline Vector3 GetUpVector(const Vector3& _Vec);

    // @brief Computes the yaw of a 3D vector.
    // @param _Vec Input vector.
    // @return Yaw angle in radians.
    inline float GetVectorYaw(const Vector3& _Vec);

    // @brief Computes the pitch of a 3D vector.
    // @param _Vec Input vector.
    // @return Pitch angle in radians.
    inline float GetVectorPitch(const Vector3& _Vec);

    // @brief Creates a vector from yaw and pitch.
    // @param _Yaw Rotation around Y-axis in radians.
    // @param _Pitch Rotation around X-axis in radians.
    // @return Unit vector.
    inline constexpr Vector3 GetVectorFromYawPitch(float _Yaw, float _Pitch) noexcept;

    // @brief Rotates a vector around an axis.
    // @param _Vec Input vector.
    // @param _Axis Rotation axis.
    // @param _Angle Rotation angle in radians.
    // @return Rotated vector around an axis.
    inline Vector3 RotateAroundAxis(const Vector3& _Vec, const Vector3& _Axis, float _Angle);

    // @brief Computes squared norm of a quaternion.
    // @param _Quat Input quaternion.
    // @return Squared Norm of the quaternion.
    inline constexpr float SqrNorm(const Quaternion& _Quat) noexcept;

    // @brief Computes norm of a quaternion.
    // @param _Quat Input quaternion.
    // @return Norm of the quaternion.
    inline float Norm(const Quaternion& _Quat) noexcept;

    // @brief Normalizes a quaternion.
    // @param _Quat Input quaternion.
    // @return Normalized quaternion.
    inline Quaternion Normalize(const Quaternion& _Quat);

    // @brief Computes conjugate of a quaternion.
    // @param _Quat Input quaternion.
    // @return Conjugate quaternion.
    inline constexpr Quaternion Conjugate(const Quaternion& _Quat) noexcept;

    // @brief Computes inverse of a quaternion.
    // @param _Quat Input quaternion.
    // @return Inverse quaternion.
    inline Quaternion Inverse(const Quaternion& _Quat);



    } // namespace Math

#include "SMath_impl.h"