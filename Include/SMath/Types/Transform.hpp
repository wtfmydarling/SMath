#pragma once

#include <stdexcept>

#include "Quaternion.hpp"
#include "Vector3.hpp"

namespace smath {
	struct Transform {
        Vector3 Translation;
        Quaternion Rotation;
        Vector3 Scale;

        inline constexpr Transform(Vector3 _Pos = {0, 0, 0}, Quaternion _Rot = {},
                                   Vector3 _Scale = {1, 1, 1}) noexcept;
	};

    using Trans = Transform;

} // namespace smath

#include "Transform_impl.hpp"