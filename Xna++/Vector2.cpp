#include "Vector2.hpp"
#include "Point.hpp"

namespace Xna {
	Vector2::Vector2() {}
	Vector2::Vector2(double x, double y) :
		X(x), Y(y) {}
	Vector2::Vector2(double v) :
		X(v), Y(v) {}
	Vector2::Vector2(int32_t x, int32_t y) :
		X(static_cast<double>(x)),
		Y(static_cast<double>(y)) {}
	Vector2::Vector2(Point p) :
		X(static_cast<double>(p.X)),
		Y(static_cast<double>(p.Y)) {}

	const Vector2 Vector2::Zero = Vector2();
	const Vector2 Vector2::One = Vector2(1.0, 1.0);
	const Vector2 Vector2::UnitX = Vector2(1.0, 0.0);
	const Vector2 Vector2::UnitY = Vector2(0.0, 1.0);

	Vector2 Vector2::Add(Vector2 const& v1, Vector2 const& v2) {
		return Vector2(v1.X + v2.X, v1.Y + v2.Y);
	}

	Vector2 Vector2::Subtract(Vector2 const& v1, Vector2 const& v2) {
		return Vector2(v1.X - v2.X, v1.Y - v2.Y);
	}

	Vector2 Vector2::Multiply(Vector2 const& v1, Vector2 const& v2) {
		return Vector2(v1.X * v2.X, v1.Y * v2.Y);
	}

	Vector2 Vector2::Multiply(Vector2 const& v1, double v) {
		return Vector2(v1.X * v, v1.Y * v);
	}

	Vector2 Vector2::Divide(Vector2 const& v1, Vector2 const& v2) {
		double x = v1.X != 0 ? v1.X / v2.X : 0;
		double y = v2.Y != 0 ? v1.Y / v2.Y : 0;

		return Vector2(x, y);
	}

	Vector2 Vector2::Divide(Vector2 const& v1, double v) {
		return v == 0 ? Vector2() : Vector2(v1.X / v, v1.Y / v);
	}

	Vector2 Vector2::Barycentric(Vector2 const& v1, Vector2 const& v2, Vector2 const& v3, double amount1, double amount2) {

	}
}

