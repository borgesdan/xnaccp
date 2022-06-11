#include <cmath>
#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "MathHelper.hpp"
#include "Matrix.hpp"

namespace Xna {
	Vector4::Vector4() {}
	Vector4::Vector4(double x, double y, double z, double w) :
		X(x), Y(y), Z(z), W(w) {}
	Vector4::Vector4(Vector2 value, double z, double w) :
		X(value.X), Y(value.Y), Z(z), W(w) {}
	Vector4::Vector4(Vector3 value, double w) :
		X(value.X), Y(value.Y), Z(value.Z), W(w) {}
	Vector4::Vector4(double value) :
		X(value), Y(value), Z(value), W(value) {}

	const Vector4 Zero = Vector4();
	const Vector4 One = Vector4(1.0);
	const Vector4 UnitX = Vector4(1.0, 0.0, 0.0, 0.0);
	const Vector4 UnitY = Vector4(0.0, 1.0, 0.0, 0.0);
	const Vector4 UnitZ = Vector4(0.0, 0.0, 1.0, 0.0);
	const Vector4 UnitW = Vector4(0.0, 0.0, 0.0, 1.0);

	Vector4 Vector4::Add(Vector4 const& v1, Vector4 const& v2) {
		return Vector4(v1.X + v2.X,
			v1.Y + v2.Y,
			v1.Z + v2.Z,
			v1.W + v2.W
		);
	}

	Vector4 Vector4::Subtract(Vector4 const& v1, Vector4 const& v2) {
		return Vector4(v1.X - v2.X,
			v1.Y - v2.Y,
			v1.Z - v2.Z,
			v1.W - v2.W
		);
	}

	Vector4 Vector4::Multiply(Vector4 const& v1, Vector4 const& v2) {
		return Vector4(v1.X * v2.X,
			v1.Y * v2.Y,
			v1.Z * v2.Z,
			v1.W * v2.W
		);
	}

	Vector4 Vector4::Multiply(Vector4 const& v1, double d) {
		return Vector4(v1.X * d,
			v1.Y * d,
			v1.Z * d,
			v1.W * d
		);
	}

	Vector4 Vector4::Divide(Vector4 const& v1, Vector4 const& v2) {
		double x = v1.X != 0 ? v1.X / v2.X : 0;
		double y = v2.Y != 0 ? v1.Y / v2.Y : 0;
		double z = v2.Z != 0 ? v1.Z / v2.Z : 0;
		double w = v2.W != 0 ? v1.W / v2.W : 0;

		return Vector4(x, y, z, w);
	}

	Vector4 Vector4::Divide(Vector4 const& v1, double d) {
		return d == 0 ? Vector4() : Vector4(v1.X / d, v1.Y / d, v1.Z / d, v1.W / d);
	}

	Vector4 Vector4::Barycentric(Vector4 const& v1, Vector4 const& v2, Vector4 const& v3, double amount1, double amount2) {
		return Vector4(
			MathHelper::Barycentric(v1.X, v2.X, v3.X, amount1, amount2),
			MathHelper::Barycentric(v1.Y, v2.Y, v3.Y, amount1, amount2),
			MathHelper::Barycentric(v1.Z, v2.Z, v3.Z, amount1, amount2),
			MathHelper::Barycentric(v1.W, v2.W, v3.W, amount1, amount2));
	}

	Vector4 Vector4::CatmullRom(Vector4 const& v1, Vector4 const& v2, Vector4 const& v3, Vector4 const& v4, double amount) {
		return Vector4(
			MathHelper::CatmullRom(v1.X, v2.X, v3.X, v4.X, amount),
			MathHelper::CatmullRom(v1.Y, v2.Y, v3.Y, v4.Y, amount),
			MathHelper::CatmullRom(v1.Z, v2.Z, v3.Z, v4.Z, amount),
			MathHelper::CatmullRom(v1.W, v2.W, v3.W, v4.W, amount));
	}

	Vector4 Vector4::Ceiling(Vector4 const& v) {
		return Vector4(
			ceil(v.X),
			ceil(v.Y),
			ceil(v.Z),
			ceil(v.W)
		);
	}

	Vector4 Vector4::Clamp(Vector4 const& v, Vector4 const& min, Vector4 const& max) {
		return Vector4(
			MathHelper::Clamp(v.X, min.X, max.X),
			MathHelper::Clamp(v.Y, min.Y, max.Y),
			MathHelper::Clamp(v.Z, min.Z, max.Z),
			MathHelper::Clamp(v.W, min.W, max.W)
		);
	}

	double Vector4::Distance(Vector4 const& v1, Vector4 const& v2) {
		return sqrt(DistanceSquared(v1, v2));
	}

	double Vector4::DistanceSquared(Vector4 const& v1, Vector4 const& v2) {
		return (v1.W - v2.W) * (v1.W - v2.W) +
			(v1.X - v2.X) * (v1.X - v2.X) +
			(v1.Y - v2.Y) * (v1.Y - v2.Y) +
			(v1.Z - v2.Z) * (v1.Z - v2.Z);
	}

	double Vector4::Dot(Vector4 const& v1, Vector4 v2) {
		return v1.X * v2.X
			+ v1.Y * v2.Y
			+ v1.Z * v2.Z
			+ v1.W * v2.W;
	}

	Vector4 Vector4::Floor(Vector4 const& v) {
		return Vector4(floor(v.X),
			floor(v.Y),
			floor(v.Z),
			floor(v.W)
		);
	}

	Vector4 Vector4::Hermite(Vector4 const& v1, Vector4 const& tan1, Vector4 const& v2, Vector4 tan2, double amount) {
		return Vector4(MathHelper::Hermite(v1.X, tan1.X, v2.X, tan2.X, amount),
			MathHelper::Hermite(v1.Y, tan1.Y, v2.Y, tan2.Y, amount),
			MathHelper::Hermite(v1.Z, tan1.Z, v2.Z, tan2.Z, amount),
			MathHelper::Hermite(v1.W, tan1.W, v2.W, tan2.W, amount)
		);
	}

	Vector4 Vector4::Lerp(Vector4 const& v1, Vector4 const& v2, double amount) {
		return Vector4(
			MathHelper::Lerp(v1.X, v2.X, amount),
			MathHelper::Lerp(v1.Y, v2.Y, amount),
			MathHelper::Lerp(v1.Z, v2.Z, amount),
			MathHelper::Lerp(v1.W, v2.W, amount));
	}

	Vector4 Vector4::LerpPrecise(Vector4 const& v1, Vector4 v2, double amount) {
		return Vector4(
			MathHelper::LerpPrecise(v1.X, v2.X, amount),
			MathHelper::LerpPrecise(v1.Y, v2.Y, amount),
			MathHelper::LerpPrecise(v1.Z, v2.Z, amount),
			MathHelper::LerpPrecise(v1.W, v2.W, amount));
	}

	Vector4 Vector4::Max(Vector4 const& v1, Vector4 const& v2) {
		return Vector4(
			MathHelper::Max(v1.X, v2.X),
			MathHelper::Max(v1.Y, v2.Y),
			MathHelper::Max(v1.Z, v2.Z),
			MathHelper::Max(v1.W, v2.W));
	}

	Vector4 Vector4::Min(Vector4 const& v1, Vector4 const& v2) {
		return Vector4(
			MathHelper::Min(v1.X, v2.X),
			MathHelper::Min(v1.Y, v2.Y),
			MathHelper::Min(v1.Z, v2.Z),
			MathHelper::Min(v1.W, v2.W));
	}

	Vector4 Vector4::Negate(Vector4 const& v) {
		return Vector4(-v.X, -v.Y, -v.Z, -v.W);
	}

	Vector4 Vector4::Normalize(Vector4 const& v) {
		double factor = 1.0 / sqrt((v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z) + (v.W * v.W));
		return Vector4(v.X * factor, v.Y * factor, v.Z * factor, v.W * factor);
	}


	Vector4 Vector4::Round(Vector4 const& v) {
		return Vector4(
			round(v.X),
			round(v.Y),
			round(v.Z),
			round(v.W)
		);
	}

	Vector4 Vector4::SmoothStep(Vector4 const& v1, Vector4 const& v2, double amount) {
		return Vector4(
			MathHelper::SmoothStep(v1.X, v2.X, amount),
			MathHelper::SmoothStep(v1.Y, v2.Y, amount),
			MathHelper::SmoothStep(v1.Z, v2.Z, amount),
			MathHelper::SmoothStep(v1.W, v2.W, amount));
	}

	Vector4 Vector4::Transform(Vector2 const& v, Matrix const& m) {
		return Vector4(
			(v.X * m.M11) + (v.Y * m.M21) + m.M41,
			(v.X * m.M12) + (v.Y * m.M22) + m.M42,
			(v.X * m.M13) + (v.Y * m.M23) + m.M43,
			(v.X * m.M14) + (v.Y * m.M24) + m.M44
		);
	}

	Vector4 Vector4::Transform(Vector3 const& v, Matrix const& m) {
		return Vector4(
			(v.X * m.M11) + (v.Y * m.M21) + (v.Z * m.M31) + m.M41,
			(v.X * m.M12) + (v.Y * m.M22) + (v.Z * m.M32) + m.M42,
			(v.X * m.M13) + (v.Y * m.M23) + (v.Z * m.M33) + m.M43,
			(v.X * m.M14) + (v.Y * m.M24) + (v.Z * m.M34) + m.M44
		);
	}

	Vector4 Vector4::Transform(Vector4 const& v, Matrix const& m) {
		return Vector4(
			(v.X * m.M11) + (v.Y * m.M21) + (v.Z * m.M31) + (v.W * m.M41),
			(v.X * m.M12) + (v.Y * m.M22) + (v.Z * m.M32) + (v.W * m.M42),
			(v.X * m.M13) + (v.Y * m.M23) + (v.Z * m.M33) + (v.W * m.M43),
			(v.X * m.M14) + (v.Y * m.M24) + (v.Z * m.M34) + (v.W * m.M44)
		);
	}

	bool Vector4::Transfrom(std::vector<Vector4> const& source, size_t sourceIndex,
		Matrix const& m, std::vector<Vector4>& destination, size_t destinationIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destinationIndex + length) {
			return false;
		}

		for (size_t i = 0; i < length; i++) {
			Vector4 value = source[sourceIndex + i];
			destination[destinationIndex + i] = Vector4::Transform(value, m);
		}

		return true;
	}	

	bool Vector4::Transform(std::vector<Vector4> const& source, Matrix const& m, std::vector<Vector4>& destination) {
		return Vector4::Transfrom(source, 0, m, destination, 0, source.size());
	}

	void Vector4::Ceiling() {
		Vector4 value = Vector4::Ceiling(*this);
		X = value.X;
		Y = value.Y;
		Z = value.Z;
		W = value.W;
	}

	void Vector4::Floor() {
		Vector4 value = Vector4::Floor(*this);
		X = value.X;
		Y = value.Y;
		Z = value.Z;
		W = value.W;
	}

	double Vector4::Length() const {
		return sqrt(LengthSquared());
	}

	double Vector4::LengthSquared() const {
		return (X * X) + (Y * Y) + (Z * Z) + (W * W);
	}

	void Vector4::Normalize() {
		Vector4 value = Vector4::Normalize(*this);
		X = value.X;
		Y = value.Y;
		Z = value.Z;
		W = value.W;
	}

	void Vector4::Round() {
		Vector4 value = Vector4::Round(*this);
		X = value.X;
		Y = value.Y;
		Z = value.Z;
		W = value.W;
	}

	void Vector4::Deconstruct(double& x, double& y, double& z, double& w) const {
		x = X;
		y = Y;
		z = Z;
		w = W;
	}

	bool Vector4::Equals(Vector4 other) const {
		return X == other.X
			&& Y == other.Y
			&& Z == other.Z
			&& W == other.W;
	}

	Vector4 Vector4::operator- (Vector4 v) {
		return Vector4::Negate(v);
	}

	Vector4 operator+ (Vector4 v1, Vector4 v2) {
		return Vector4::Add(v1, v2);
	}

	Vector4 operator- (Vector4 v1, Vector4 v2) {
		return Vector4::Subtract(v1, v2);
	}

	Vector4 operator* (Vector4 v1, Vector4 v2) {
		return Vector4::Multiply(v1, v2);
	}

	Vector4 operator* (Vector4 v, double d) {
		return Vector4::Multiply(v, d);
	}

	Vector4 operator* (double d, Vector4 v) {
		return Vector4::Multiply(v, d);
	}

	Vector4 operator/ (Vector4 v1, Vector4 v2) {
		return Vector4::Divide(v1, v2);
	}

	Vector4 operator/ (Vector4 v, double d) {
		return Vector4::Divide(v, d);
	}

	bool operator== (Vector4 v1, Vector4 v2) {
		return v1.Equals(v2);
	}

	bool operator!= (Vector4 v1, Vector4 v2) {
		return !v1.Equals(v2);
	}
}