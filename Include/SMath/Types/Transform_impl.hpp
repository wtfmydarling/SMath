#pragma once

#include "Transform.hpp"

namespace smath {
    inline constexpr smath::Transform::Transform(Vector3 _Pos, Quaternion _Rot,
                                                 Vector3 _Scale) noexcept 
    : Translation(_Pos), Rotation(_Rot), Scale(_Scale) {
    }

} // namespace smath