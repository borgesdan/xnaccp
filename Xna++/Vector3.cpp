#include "Vector3.hpp"

namespace Xna {

	Vector3::Vector3() {}
	Vector3::Vector3(double x, double y, double z) :
		X(x), Y(y), Z(z) {}

	Vector3 operator* (Vector3 v1, Vector3 v2s) {
		return Vector3();
	}

}