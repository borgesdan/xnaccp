#include "Point.hpp"
#include "Matrix.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "MathHelper.hpp"
#include "Quaternion.hpp"

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
	const Vector2 Vector2::One = Vector2(1.0);
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

	Vector2 Vector2::Multiply(Vector2 const& v1, double d) {
		return Vector2(v1.X * d, v1.Y * d);
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
		return Vector2(
			MathHelper::Barycentric(v1.X, v2.X, v3.X, amount1, amount2),
			MathHelper::Barycentric(v1.Y, v2.Y, v3.Y, amount1, amount2)
		);
	}

	Vector2 Vector2::CatmullRom(Vector2 const& v1, Vector2 const& v2, Vector2 const& v3, Vector2 const& v4, double amount) {
		return Vector2(
			MathHelper::CatmullRom(v1.X, v2.X, v3.X, v4.X, amount),
			MathHelper::CatmullRom(v1.Y, v2.Y, v3.Y, v4.Y, amount)
		);
	}

	Vector2 Vector2::Ceiling(Vector2 const& v) {		
		return Vector2(
			ceil(v.X),
			ceil(v.Y)
		);
	}

	Vector2 Vector2::Clamp(Vector2 const& v, Vector2 const& min, Vector2 const& max) {
		return Vector2(
			MathHelper::Clamp(v.X, min.X, max.X),
			MathHelper::Clamp(v.Y, min.Y, max.Y)
		);
	}
	
	double Vector2::Distance(Vector2 const& v1, Vector2 const& v2) {
		return sqrt(DistanceSquared(v1, v2));
	}

	double Vector2::DistanceSquared(Vector2 const& v1, Vector2 const& v2) {
		double _v1 = v1.X - v2.X;
		double _v2 = v1.Y - v2.Y;

		return (_v1 * _v1) + (_v2 * _v2);
	}

	double Vector2::Dot(Vector2 const& v1, Vector2 v2) {
		return (v1.X * v2.X) + (v1.Y * v2.Y);
	}

	Vector2 Vector2::Floor(Vector2 const& v) {
		return Vector2(floor(v.X), floor(v.Y));
	}

	Vector2 Vector2::Hermite(Vector2 const& v1, Vector2 const& tan1, Vector2 const& v2, Vector2 tan2, double amount) {
		return Vector2(
			MathHelper::Hermite(v1.X, tan1.X, v2.X, tan2.X, amount),
			MathHelper::Hermite(v1.Y, tan1.Y, v2.Y, tan2.Y, amount)
		);
	}

	Vector2 Vector2::Lerp(Vector2 const& v1, Vector2 const& v2, double amount) {
		return Vector2(
			MathHelper::Lerp(v1.X, v2.X, amount),
			MathHelper::Lerp(v1.Y, v2.Y, amount)
		);
	}

	Vector2 Vector2::LerpPrecise(Vector2 const& v1, Vector2 v2, double amount) {
		return Vector2(
			MathHelper::LerpPrecise(v1.X, v2.X, amount),
			MathHelper::LerpPrecise(v1.Y, v2.Y, amount)
		);
	}

	Vector2 Vector2::Max(Vector2 const& v1, Vector2 const& v2) {
		return Vector2(
			MathHelper::Max(v1.X, v2.X),
			MathHelper::Max(v1.Y, v2.Y)
		);
	}

	Vector2 Vector2::Min(Vector2 const& v1, Vector2 const& v2) {
		return Vector2(
			MathHelper::Min(v1.X, v2.X),
			MathHelper::Min(v1.Y, v2.Y)
		);
	}

	Vector2 Vector2::Negate(Vector2 const& v) {
		return Vector2(-v.X, -v.Y);
	}

	Vector2 Vector2::Normalize(Vector2 const& v) {
		double val = 1.0 / sqrt((v.X * v.X) + (v.Y * v.Y));
		
		double x = v.X * val;
		double y = v.Y * val;

		return Vector2(x, y);
	}

	Vector2 Vector2::Reflect(Vector2 const& v, Vector2 const& normal) {
		
		double val = 2.0 * ((v.X * normal.X) + (v.Y * normal.Y));

		return Vector2(
			v.X - (normal.X * val),
			v.Y - (normal.Y * val)
		);
	}

	Vector2 Vector2::Round(Vector2 const& v) {		
		return Vector2(
			round(v.X),
			round(v.Y)
		);
	}

	Vector2 Vector2::SmoothStep(Vector2 const& v1, Vector2 const& v2, double amount) {
		return Vector2(
			MathHelper::SmoothStep(v1.X, v2.X, amount),
			MathHelper::SmoothStep(v1.Y, v2.Y, amount));
	}

	Vector2 Vector2::Transform(Vector2 const& position, Matrix const& m) {
		return Vector2(
			(position.X * m.M11) + (position.Y * m.M21) + m.M41,
			(position.X * m.M12) + (position.Y * m.M22) + m.M42
		);
	}

	Vector2 Vector2::Transform(Vector2 const& v, Quaternion const& q) {
		Vector3 rot1 = Vector3(q.X + q.X, q.Y + q.Y, q.Z + q.Z);
		Vector3 rot2 = Vector3(q.X, q.X, q.W);
		Vector3 rot3 = Vector3(1.0, q.Y, q.Z);
		Vector3 rot4 = rot1 * rot2;
		Vector3 rot5 = rot1 * rot3;

		return Vector2(
			(v.X * (1.0 - rot5.Y - rot5.Z) + v.Y * (rot4.Y - rot4.Z)),
			(v.X * (rot4.Y + rot4.Z) + v.Y * (1.0 - rot4.X - rot5.Z))
		);
	}

	bool Vector2::Transform(std::vector<Vector2> const& source, size_t sourceIndex,
		Matrix const& m, std::vector<Vector2>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length 
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t x = 0; x < length; x++) {
			Vector2 position = source[sourceIndex + x];
			Vector2 dest = destination[destIndex + x];

			dest.X = (position.X * m.M11) + (position.Y * m.M21) + m.M41;
			dest.Y = (position.X * m.M12) + (position.Y * m.M22) + m.M42;

			destination[destIndex + x] = dest;
		}

		return true;
	}

	bool Vector2::Transform(std::vector<Vector2> const& source, size_t sourceIndex,
		Quaternion const& q, std::vector<Vector2>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t x = 0; x < length; x++) {
			Vector2 position = source[sourceIndex + x];
			Vector2 dest = destination[destIndex + x];
			Vector2 vec = Transform(position, q);

			dest.X = vec.X;
			dest.Y = vec.Y;

			destination[destIndex + x] = dest;
		}

		return true;
	}

	bool Vector2::Transform(std::vector<Vector2> const& source, Matrix const& m, std::vector<Vector2>& destination) {
		return Transform(source, 0, m, destination, 0, source.size());
	}

	bool Vector2::Transform(std::vector<Vector2> const& source, Quaternion const& q, std::vector<Vector2>& destination) {
		return Transform(source, 0, q, destination, 0, source.size());
	}

	Vector2 Vector2::TransformNormal(Vector2 const& normal, Matrix m) {
		return Vector2((normal.X * m.M11) + (normal.Y * m.M21),
			(normal.X * m.M12) + (normal.Y * m.M22));
	}

	bool Vector2::TransformNormal(std::vector<Vector2> const& source, size_t sourceIndex,
		Matrix const& m, std::vector<Vector2>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t i = 0; i < length; i++) {
			Vector2 normal = source[sourceIndex + i];

			destination[destIndex + i] = Vector2(
				(normal.X * m.M11) + (normal.Y * m.M21),
				(normal.X * m.M12) + (normal.Y * m.M22)
			);
		}

		return true;
	}

	bool Vector2::TransformNormal(std::vector<Vector2> const& source, 
		Matrix const& m, std::vector<Vector2>& destination) {
		
		return TransformNormal(source, 0, m, destination, 0, source.size());
	}

	void Vector2::Ceiling() {
		Vector2 vec = Vector2::Ceiling(*this);
		X = vec.X;
		Y = vec.Y;
	}

	void Vector2::Floor() {
		Vector2 vec = Vector2::Floor(*this);
		X = vec.X;
		Y = vec.Y;
	}

	double Vector2::Length() const {
		return sqrt(LengthSquared());
	}

	double Vector2::LengthSquared() const {
		return (X * X) + (Y * Y);
	}

	void Vector2::Normalize() {
		Vector2 vec = Vector2::Normalize(*this);
		X = vec.X;
		Y = vec.Y;
	}

	void Vector2::Round() {
		Vector2 vec = Vector2::Round(*this);
		X = vec.X;
		Y = vec.Y;
	}

	Point Vector2::ToPoint() {
		Vector2 vec = *this;
		return Point(vec);
	}

	void Vector2::Deconstruct(double& x, double& y) const {
		x = X;
		y = Y;
	}

	bool Vector2::Equals(Vector2 other) const {
		return X == other.X && Y == other.Y;
	}

	Vector2 Vector2::operator- (Vector2 v) {
		return Vector2::Negate(v);
	}

	Vector2 operator+ (Vector2 v1, Vector2 v2) {
		return Vector2::Add(v1, v2);
	}

	Vector2 operator- (Vector2 v1, Vector2 v2) {
		return Vector2::Subtract(v1, v2);
	}

	Vector2 operator* (Vector2 v1, Vector2 v2) {
		return Vector2::Multiply(v1, v2);
	}

	Vector2 operator* (Vector2 v, double d) {
		return Vector2::Multiply(v, d);
	}

	Vector2 operator* (double d, Vector2 v) {
		return Vector2::Multiply(v, d);
	}

	Vector2 operator/ (Vector2 v1, Vector2 v2) {
		return Vector2::Divide(v1, v2);
	}

	Vector2 operator/ (Vector2 v, double d) {
		return Vector2::Divide(v, d);
	}

	bool operator== (Vector2 v1, Vector2 v2) {
		return v1.Equals(v2);
	}	
	
	bool operator!= (Vector2 v1, Vector2 v2) {
		return !v1.Equals(v2);
	}
}

