#include <cmath>
#include "Matrix.hpp"
#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Quaternion.hpp"
#include "MathHelper.hpp"

namespace Xna {

	Vector3::Vector3() {}
	Vector3::Vector3(double x, double y, double z) :
		X(x), Y(y), Z(z) {}
	Vector3::Vector3(double value) :
		X(value), Y(value), Z(value) {}
	Vector3::Vector3(Vector2 value, double z) :
		X(value.X), Y(value.Y), Z(z) {}

	const Vector3 Zero = Vector3();
	const Vector3 One = Vector3(1.0);
	const Vector3 UnitX = Vector3(1.0, 0.0, 0.0);
	const Vector3 UnitY = Vector3(0.0, 1.0, 0.0);
	const Vector3 UnitZ = Vector3(0.0, 0.0, 1.0);
	const Vector3 Up = Vector3(0.0, 1.0, 0.0);
	const Vector3 Down = Vector3(0.0, -1.0, 0.0);
	const Vector3 Right = Vector3(1.0, 0.0, 0.0);
	const Vector3 Left = Vector3(-1.0, 0.0, 0.0);
	const Vector3 Forward = Vector3(0.0, 0.0, -1.0);
	const Vector3 Backward = Vector3(0.0, 0.0, 1.0);

	Vector3 Vector3::Add(Vector3 const& v1, Vector3 const& v2) {
		return Vector3(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	Vector3 Vector3::Subtract(Vector3 const& v1, Vector3 const& v2) {
		return Vector3(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	Vector3 Vector3::Multiply(Vector3 const& v1, Vector3 const& v2) {
		return Vector3(v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z);
	}

	Vector3 Vector3::Multiply(Vector3 const& v1, double d) {
		return Vector3(v1.X * d, v1.Y * d, v1.Z * d);
	}

	Vector3 Vector3::Divide(Vector3 const& v1, Vector3 const& v2) {
		double x = v1.X != 0 ? v1.X / v2.X : 0;
		double y = v2.Y != 0 ? v1.Y / v2.Y : 0;
		double z = v2.Z != 0 ? v1.Z / v2.Z : 0;

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Divide(Vector3 const& v1, double d) {
		return d == 0 ? Vector3() : Vector3(v1.X / d, v1.Y / d, v1.Z / d);
	}

	Vector3 Vector3::Barycentric(Vector3 const& v1, Vector3 const& v2, Vector3 const& v3, double amount1, double amount2) {
		return Vector3(
			MathHelper::Barycentric(v1.X, v2.X, v3.X, amount1, amount2),
			MathHelper::Barycentric(v1.Y, v2.Y, v3.Y, amount1, amount2),
			MathHelper::Barycentric(v1.Z, v2.Z, v3.Z, amount1, amount2)
		);
	}

	Vector3 Vector3::CatmullRom(Vector3 const& v1, Vector3 const& v2, Vector3 const& v3, Vector3 const& v4, double amount) {
		return Vector3(
			MathHelper::CatmullRom(v1.X, v2.X, v3.X, v4.X, amount),
			MathHelper::CatmullRom(v1.Y, v2.Y, v3.Y, v4.Y, amount),
			MathHelper::CatmullRom(v1.Z, v2.Z, v3.Z, v4.Z, amount)
		);
	}

	Vector3 Vector3::Ceiling(Vector3 const& v) {
		return Vector3(
			ceil(v.X),
			ceil(v.Y),
			ceil(v.Z)
		);
	}

	Vector3 Vector3::Clamp(Vector3 const& v, Vector3 const& min, Vector3 const& max) {
		return Vector3(
			MathHelper::Clamp(v.X, min.X, max.X),
			MathHelper::Clamp(v.Y, min.Y, max.Y),
			MathHelper::Clamp(v.Z, min.Z, max.Z));
	}

	Vector3 Vector3::Cross(Vector3 const& v1, Vector3 const& v2) {
		double x = v1.Y * v2.Z - v2.Y * v1.Z;
		double y = -(v1.X * v2.Z - v2.X * v1.Z);
		double z = v1.X * v2.Y - v2.X * v1.Y;

		return Vector3(x, y, z);
	}

	double Vector3::Distance(Vector3 const& v1, Vector3 const& v2) {
		return sqrt(DistanceSquared(v1, v2));
	}

	double Vector3::DistanceSquared(Vector3 const& v1, Vector3 const& v2) {
		return  (v1.X - v2.X) * (v1.X - v2.X) +
			(v1.Y - v2.Y) * (v1.Y - v2.Y) +
			(v1.Z - v2.Z) * (v1.Z - v2.Z);
	}

	double Vector3::Dot(Vector3 const& v1, Vector3 v2) {
		return v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
	}

	Vector3 Vector3::Floor(Vector3 const& v) {
		return Vector3(floor(v.X), floor(v.Y), floor(v.Z));
	}

	Vector3 Vector3::Hermite(Vector3 const& v1, Vector3 const& tan1, Vector3 const& v2, Vector3 tan2, double amount) {
		return Vector3(
			MathHelper::Hermite(v1.X, tan1.X, v2.X, tan2.X, amount),
			MathHelper::Hermite(v1.Y, tan1.Y, v2.Y, tan2.Y, amount),
			MathHelper::Hermite(v1.Z, tan1.Z, v2.Z, tan2.Z, amount)
		);
	}

	Vector3 Vector3::Lerp(Vector3 const& v1, Vector3 const& v2, double amount) {
		return Vector3(
			MathHelper::Lerp(v1.X, v2.X, amount),
			MathHelper::Lerp(v1.Y, v2.Y, amount),
			MathHelper::Lerp(v1.Z, v2.Z, amount)
		);
	}

	Vector3 Vector3::LerpPrecise(Vector3 const& v1, Vector3 v2, double amount) {
		return Vector3(
			MathHelper::LerpPrecise(v1.X, v2.X, amount),
			MathHelper::LerpPrecise(v1.Y, v2.Y, amount),
			MathHelper::LerpPrecise(v1.Z, v2.Z, amount)
		);
	}

	Vector3 Vector3::Max(Vector3 const& v1, Vector3 const& v2) {
		return Vector3(
			MathHelper::Max(v1.X, v2.X),
			MathHelper::Max(v1.Y, v2.Y),
			MathHelper::Max(v1.Z, v2.Z));
	}

	Vector3 Vector3::Min(Vector3 const& v1, Vector3 const& v2) {
		return Vector3(
			MathHelper::Min(v1.X, v2.X),
			MathHelper::Min(v1.Y, v2.Y),
			MathHelper::Min(v1.Z, v2.Z));
	}

	Vector3 Vector3::Negate(Vector3 const& v) {
		return Vector3(-v.X, -v.Y, -v.Z);
	}

	Vector3 Vector3::Normalize(Vector3 const& v) {
		double factor = 1.0 / sqrt((v.X * v.X) + (v.Y * v.Y) + (v.Z * v.Z));

		double x = v.X * factor;
		double y = v.Y * factor;
		double z = v.Z * factor;

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Reflect(Vector3 const& v, Vector3 const& normal) {
		double dotProduct = ((v.X * normal.X) + (v.Y * normal.Y)) + (v.Z * normal.Z);

		return Vector3(
			v.X - (2.0 * normal.X) * dotProduct,
			v.Y - (2.0 * normal.Y) * dotProduct,
			v.Z - (2.0 * normal.Z) * dotProduct
		);
	}

	Vector3 Vector3::Round(Vector3 const& v) {
		return Vector3(
			round(v.X),
			round(v.Y),
			round(v.Z)
		);
	}

	Vector3 Vector3::SmoothStep(Vector3 const& v1, Vector3 const& v2, double amount) {
		return Vector3(
			MathHelper::SmoothStep(v1.X, v2.X, amount),
			MathHelper::SmoothStep(v1.Y, v2.Y, amount),
			MathHelper::SmoothStep(v1.Z, v2.Z, amount)
		);
	}	

	Vector3 Vector3::Transform(Vector3 const& position, Matrix const& m) {
		double x = (position.X * m.M11) + (position.Y * m.M21) + (position.Z * m.M31) + m.M41;
		double y = (position.X * m.M12) + (position.Y * m.M22) + (position.Z * m.M32) + m.M42;
		double z = (position.X * m.M13) + (position.Y * m.M23) + (position.Z * m.M33) + m.M43;
		
		return Vector3(x, y, z);
	}

	Vector3 Vector3::Transform(Vector3 const& v, Quaternion const& q) {
		double x = 2 * (q.Y * v.Z - q.Z * v.Y);
		double y = 2 * (q.Z * v.X - q.X * v.Z);
		double z = 2 * (q.X * v.Y - q.Y * v.X);

		return Vector3(
			v.X + x * q.W + (q.Y * z - q.Z * y),
			v.Y + y * q.W + (q.Z * x - q.X * z),
			v.Z + z * q.W + (q.X * y - q.Y * x)
		);
	}

	bool Vector3::Transform(std::vector<Vector3> const& source, size_t sourceIndex,
		Matrix const& m, std::vector<Vector3>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t i = 0; i < length; i++) {
			Vector3 position = source[sourceIndex + i];
			destination[destIndex + i] =
				Vector3(
					(position.X * m.M11) + (position.Y * m.M21) + (position.Z * m.M31) + m.M41,
					(position.X * m.M12) + (position.Y * m.M22) + (position.Z * m.M32) + m.M42,
					(position.X * m.M13) + (position.Y * m.M23) + (position.Z * m.M33) + m.M43
				);
		}

		return true;
	}

	bool Vector3::Transform(std::vector<Vector3> const& source, size_t sourceIndex,
		Quaternion const& q, std::vector<Vector3>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t i = 0; i < length; i++) {
			Vector3 position = source[sourceIndex + i];

			double x = 2 * (q.Y * position.Z - q.Z * position.Y);
			double y = 2 * (q.Z * position.X - q.X * position.Z);
			double z = 2 * (q.X * position.Y - q.Y * position.X);

			destination[destIndex + i] =
				Vector3(
					position.X + x * q.W + (q.Y * z - q.Z * y),
					position.Y + y * q.W + (q.Z * x - q.X * z),
					position.Z + z * q.W + (q.X * y - q.Y * x)
				);
		}

		return true;
	}

	bool Vector3::Transform(std::vector<Vector3> const& source, Matrix const& m, std::vector<Vector3>& destination) {
		return Transform(source, 0, m, destination, 0, source.size());
	}

	bool Vector3::Transform(std::vector<Vector3> const& source, Quaternion const& q, std::vector<Vector3>& destination) {
		return Transform(source, 0, q, destination, 0, source.size());
	}

	Vector3 Vector3::TransformNormal(Vector3 const& normal, Matrix m) {
		double x = (normal.X * m.M11) + (normal.Y * m.M21) + (normal.Z * m.M31);
		double y = (normal.X * m.M12) + (normal.Y * m.M22) + (normal.Z * m.M32);
		double z = (normal.X * m.M13) + (normal.Y * m.M23) + (normal.Z * m.M33);

		return Vector3(x, y, z);
	}

	bool Vector3::TransformNormal(std::vector<Vector3> const& source, size_t sourceIndex,
		Matrix const& m, std::vector<Vector3>& destination, size_t destIndex, size_t length) {

		if (source.size() < sourceIndex + length
			|| destination.size() < destIndex + length) {
			return false;
		}

		for (size_t x = 0; x < length; x++)
		{
			Vector3 normal = source[sourceIndex + x];

			destination[destIndex + x] =
				Vector3(
					(normal.X * m.M11) + (normal.Y * m.M21) + (normal.Z * m.M31),
					(normal.X * m.M12) + (normal.Y * m.M22) + (normal.Z * m.M32),
					(normal.X * m.M13) + (normal.Y * m.M23) + (normal.Z * m.M33)
				);
		}

		return true;
	}

	bool Vector3::TransformNormal(std::vector<Vector3> const& source,
		Matrix const& m, std::vector<Vector3>& destination) {
		return TransformNormal(source, 0, m, destination, 0, source.size());
	}

	void Vector3::Ceiling() {
		Vector3 vec = Vector3::Ceiling(*this);
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
	}

	void Vector3::Floor() {
		Vector3 vec = Vector3::Floor(*this);
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
	}

	double Vector3::Length() const {
		return sqrt(LengthSquared());
	}
	double Vector3::LengthSquared() const {
		return (X * X) + (Y * Y) + (Z * Z);
	}

	void Vector3::Normalize() {
		Vector3 vec = Vector3::Normalize(*this);
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
	}

	void Vector3::Round() {
		Vector3 vec = Vector3::Round(*this);
		X = vec.X;
		Y = vec.Y;
		Z = vec.Z;
	}

	void Vector3::Deconstruct(double& x, double& y, double& z) const {
		x = X;
		y = Y;
		z = Z;
	}

	bool Vector3::Equals(Vector3 other) const {
		return X == other.X 
			&& Y == other.Y
			&& Z == other.Z;
	}

	Vector3 Vector3::operator- (Vector3 v) {
		return Vector3::Negate(v);
	}

	Vector3 operator+ (Vector3 v1, Vector3 v2) {
		return Vector3::Add(v1, v2);
	}

	Vector3 operator- (Vector3 v1, Vector3 v2) {
		return Vector3::Subtract(v1, v2);
	}

	Vector3 operator* (Vector3 v1, Vector3 v2) {
		return Vector3::Multiply(v1, v2);
	}

	Vector3 operator* (Vector3 v, double d) {
		return Vector3::Multiply(v, d);
	}

	Vector3 operator* (double d, Vector3 v) {
		return Vector3::Multiply(v, d);
	}

	Vector3 operator/ (Vector3 v1, Vector3 v2) {
		return Vector3::Divide(v1, v2);
	}

	Vector3 operator/ (Vector3 v, double d) {
		return Vector3::Divide(v, d);
	}

	bool operator== (Vector3 v1, Vector3 v2) {
		return v1.Equals(v2);
	}

	bool operator!= (Vector3 v1, Vector3 v2) {
		return !v1.Equals(v2);
	}
}