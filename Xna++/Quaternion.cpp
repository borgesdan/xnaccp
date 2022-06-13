#include <math.h>
#include "Quaternion.hpp"
#include "Vector4.hpp"
#include "Vector3.hpp"
#include "Matrix.hpp"

namespace Xna {
	Quaternion::Quaternion() {}
	Quaternion::Quaternion(Vector4 value) :
		X(value.X), Y(value.Y), Z(value.Z), W(value.W) {}
	Quaternion::Quaternion(Vector3 value, double w) :
		X(value.X), Y(value.Y), Z(value.Z), W(w) {}
	Quaternion::Quaternion(double value) :
		X(value), Y(value), Z(value), W(value) {}
	Quaternion::Quaternion(double x, double y, double z, double w) :
		X(x), Y(y), Z(z), W(w) {}

	const Quaternion Quaternion::Identity = Quaternion(0.0, 0.0, 0.0, 1.0);

	Quaternion Quaternion::Add(Quaternion const& q1, Quaternion const& q2) {
		return Quaternion(
			q1.X + q2.X,
			q1.Y + q2.Y,
			q1.Z + q2.Z,
			q1.W + q2.W
		);
	}

	Quaternion Quaternion::Subtract(Quaternion const& q1, Quaternion const& q2) {
		return Quaternion(
			q1.X - q2.X,
			q1.Y - q2.Y,
			q1.Z - q2.Z,
			q1.W - q2.W
		);
	}

	Quaternion Quaternion::Multiply(Quaternion const& q1, Quaternion const& q2) {
		Quaternion quaternion;
		double x = q1.X;
		double y = q1.Y;
		double z = q1.Z;
		double w = q1.W;
		double num4 = q2.X;
		double num3 = q2.Y;
		double num2 = q2.Z;
		double num = q2.W;
		double num12 = (y * num2) - (z * num3);
		double num11 = (z * num4) - (x * num2);
		double num10 = (x * num3) - (y * num4);
		double num9 = ((x * num4) + (y * num3)) + (z * num2);
		quaternion.X = ((x * num) + (num4 * w)) + num12;
		quaternion.Y = ((y * num) + (num3 * w)) + num11;
		quaternion.Z = ((z * num) + (num2 * w)) + num10;
		quaternion.W = (w * num) - num9;
		return quaternion;
	}

	Quaternion Quaternion::Multiply(Quaternion const& q1, double d) {
		return Quaternion(
			q1.X * d,
			q1.Y * d,
			q1.Z * d,
			q1.W * d
		);
	}

	Quaternion Quaternion::Divide(Quaternion const& q1, Quaternion const& q2) {
		Quaternion quaternion;
		double x = q1.X;
		double y = q1.Y;
		double z = q1.Z;
		double w = q1.W;
		double num14 = (((q2.X * q2.X) + (q2.Y * q2.Y)) + (q2.Z * q2.Z)) + (q2.W * q2.W);
		double num5 = 1.0 / num14;
		double num4 = -q2.X * num5;
		double num3 = -q2.Y * num5;
		double num2 = -q2.Z * num5;
		double num = q2.W * num5;
		double num13 = (y * num2) - (z * num3);
		double num12 = (z * num4) - (x * num2);
		double num11 = (x * num3) - (y * num4);
		double num10 = ((x * num4) + (y * num3)) + (z * num2);

		return Quaternion(
			((x * num) + (num4 * w)) + num13,
			((y * num) + (num3 * w)) + num12,
			((z * num) + (num2 * w)) + num11,
			(w * num) - num10
		);
	}

	Quaternion Quaternion::Concatenate(Quaternion const& q1, Quaternion const& q2) {
		return Quaternion(
			((q2.X * q1.W) + (q1.X * q2.W)) + ((q2.Y * q1.Z) - (q2.Z * q1.Y)),
			((q2.Y * q1.W) + (q1.Y * q2.W)) + ((q2.Z * q1.X) - (q2.X * q1.Z)),
			((q2.Z * q1.W) + (q1.Z * q2.W)) + ((q2.X * q1.Y) - (q2.Y * q1.X)),
			(q2.W * q1.W) - (((q2.X * q1.X) + (q2.Y * q1.Y)) + (q2.Z * q1.Z))
		);
	}

	Quaternion Quaternion::Conjugate(Quaternion const& q) {
		return Quaternion(-q.X, -q.Y, -q.Z, q.W);
	}

	Quaternion Quaternion::CreateFromAxisAngle(Vector3 const& axis, double angle) {
		double half = angle * 0.5f;
		double _sin = sin(half);
		double _cos = cos(half);
		return Quaternion(axis.X * _sin, axis.Y * _sin, axis.Z * _sin, _cos);
	}

	Quaternion Quaternion::CreateFromRotationMatrix(Matrix m) {
		Quaternion quaternion;
		double _sqrt;
		double half;
		double scale = m.M11 + m.M22 + m.M33;

		if (scale > 0.0) {
			_sqrt = sqrt(scale + 1.0);
			quaternion.W = _sqrt * 0.5;
			_sqrt = 0.5 / _sqrt;

			quaternion.X = (m.M23 - m.M32) * _sqrt;
			quaternion.Y = (m.M31 - m.M13) * _sqrt;
			quaternion.Z = (m.M12 - m.M21) * _sqrt;

			return quaternion;
		}

		if ((m.M11 >= m.M22) && (m.M11 >= m.M33)) {
			_sqrt = sqrt(1.0 + m.M11 - m.M22 - m.M33);
			half = 0.5 / _sqrt;

			quaternion.X = 0.5 * _sqrt;
			quaternion.Y = (m.M12 + m.M21) * half;
			quaternion.Z = (m.M13 + m.M31) * half;
			quaternion.W = (m.M23 - m.M32) * half;

			return quaternion;
		}

		if (m.M22 > m.M33)
		{
			_sqrt = sqrt(1.0 + m.M22 - m.M11 - m.M33);
			half = 0.5 / _sqrt;

			quaternion.X = (m.M21 + m.M12) * half;
			quaternion.Y = 0.5 * _sqrt;
			quaternion.Z = (m.M32 + m.M23) * half;
			quaternion.W = (m.M31 - m.M13) * half;

			return quaternion;
		}

		_sqrt = sqrt(1.0 + m.M33 - m.M11 - m.M22);
		half = 0.5 / _sqrt;

		quaternion.X = (m.M31 + m.M13) * half;
		quaternion.Y = (m.M32 + m.M23) * half;
		quaternion.Z = 0.5 * _sqrt;
		quaternion.W = (m.M12 - m.M21) * half;

		return quaternion;
	}
	Quaternion Quaternion::CreateFromYawPitchRoll(double yaw, double pitch, double roll) {
		double halfRoll = roll * 0.5;
		double halfPitch = pitch * 0.5;
		double halfYaw = yaw * 0.5;

		double sinRoll = sin(halfRoll);
		double cosRoll = cos(halfRoll);
		double sinPitch = sin(halfPitch);
		double cosPitch = cos(halfPitch);
		double sinYaw = sin(halfYaw);
		double cosYaw = cos(halfYaw);

		return Quaternion(
			(cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll),
			(sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll),
			(cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll),
			(cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll)
		);
	}

	double Quaternion::Dot(Quaternion const& q1, Quaternion const& q2) {
		return (((q1.X * q2.X) + (q1.Y * q2.Y)) + (q1.Z * q2.Z))
			+ (q1.W * q2.W);
	}

	Quaternion Quaternion::Inverse(Quaternion const& q) {
		Quaternion q2;
		double num2 = (((q.X * q.X) + (q.Y * q.Y)) + (q.Z * q.Z)) + (q.W * q.W);
		double num = 1.0 / num2;
		q2.X = -q.X * num;
		q2.Y = -q.Y * num;
		q2.Z = -q.Z * num;
		q2.W = q.W * num;
		return q2;
	}

	Quaternion Quaternion::Lerp(Quaternion const& q1, Quaternion const& q2, double d) {
		double num = d;
		double num2 = 1.0 - num;
		Quaternion quaternion;
		double num5 = (((q1.X * q2.X) + (q1.Y * q2.Y)) + (q1.Z * q2.Z)) + (q1.W * q2.W);

		if (num5 >= 0.0) {
			quaternion.X = (num2 * q1.X) + (num * q2.X);
			quaternion.Y = (num2 * q1.Y) + (num * q2.Y);
			quaternion.Z = (num2 * q1.Z) + (num * q2.Z);
			quaternion.W = (num2 * q1.W) + (num * q2.W);
		}
		else {
			quaternion.X = (num2 * q1.X) - (num * q2.X);
			quaternion.Y = (num2 * q1.Y) - (num * q2.Y);
			quaternion.Z = (num2 * q1.Z) - (num * q2.Z);
			quaternion.W = (num2 * q1.W) - (num * q2.W);
		}

		double num4 = (((quaternion.X * quaternion.X) + (quaternion.Y * quaternion.Y))
			+ (quaternion.Z * quaternion.Z)) + (quaternion.W * quaternion.W);
		double num3 = 1.0 / sqrt(num4);
		quaternion.X *= num3;
		quaternion.Y *= num3;
		quaternion.Z *= num3;
		quaternion.W *= num3;
		return quaternion;
	}

	Quaternion Quaternion::SLerp(Quaternion const& q1, Quaternion const& q2, double d) {
		double num2;
		double num3;
		double num = d;
		double num4 = (((q1.X * q2.X) + (q1.Y * q2.Y)) + (q1.Z * q2.Z)) + (q1.W * q2.W);
		bool flag = false;

		if (num4 < 0.0) {
			flag = true;
			num4 = -num4;
		}

		if (num4 > 0.999999) {
			num3 = 1.0 - num;
			num2 = flag ? -num : num;
		}
		else {
			double num5 = acos(num4);
			double num6 = 1.0 / sin(num5);
			num3 = sin((1.0 - num) * num5) * num6;
			num2 = flag ? (-sin(num * num5) * num6) : sin(num * num5) * num6;
		}

		return Quaternion(
			(num3 * q1.X) + (num2 * q2.X),
			(num3 * q1.Y) + (num2 * q2.Y),
			(num3 * q1.Z) + (num2 * q2.Z),
			(num3 * q1.W) + (num2 * q2.W)
		);
	}
	Quaternion Quaternion::Negate(Quaternion const& q) {
		return Quaternion(-q.X, -q.Y, -q.Z, -q.W);
	}

	Quaternion Quaternion::Normalize(Quaternion const& q) {
		double num = 1.0 / sqrt((q.X * q.X) + (q.Y * q.Y) + (q.Z * q.Z) + (q.W * q.W));
		
		return Quaternion(
			q.X * num,
			q.Y * num,
			q.Z * num,
			q.W * num
		);
	}

	void Quaternion::Conjugate() {
		X = -X;
		Y = -Y;
		Z = -Z;
	}

	bool Quaternion::Equals(Quaternion other) {
		return X == other.X 
			&& Y == other.Y 
			&& Z == other.Z 
			&& W == other.W;
	}

	double Quaternion::Length() {
		return sqrt(LengthSquared());
	}

	double Quaternion::LengthSquared() {
		return (X * X) + (Y * Y) + (Z * Z) + (W * W);
	}
	
	void Quaternion::Normalize() {
		Quaternion q = Quaternion::Normalize(*this);
		X = q.X;
		Y = q.Y;
		Z = q.Z;
		W = q.W;
	}

	void Quaternion::Deconstruct(double& x, double& y, double& z, double& w) {
		x = X;
		y = Y;
		z = Z;
		w = W;
	}

	Quaternion Quaternion::operator- (Quaternion v) {
		return Quaternion::Negate(v);
	}

	Quaternion operator+ (Quaternion v1, Quaternion v2) {
		return Quaternion::Add(v1, v2);
	}

	Quaternion operator- (Quaternion v1, Quaternion v2) {
		return Quaternion::Subtract(v1, v2);
	}

	Quaternion operator* (Quaternion v1, Quaternion v2) {
		return Quaternion::Multiply(v1, v2);
	}

	Quaternion operator* (Quaternion v, double d) {
		return Quaternion::Multiply(v, d);
	}

	Quaternion operator* (double d, Quaternion v) {
		return Quaternion::Multiply(v, d);
	}

	Quaternion operator/ (Quaternion v1, Quaternion v2) {
		return Quaternion::Divide(v1, v2);
	}

	bool operator== (Quaternion v1, Quaternion v2) {
		return v1.Equals(v2);
	}

	bool operator!= (Quaternion v1, Quaternion v2) {
		return !v1.Equals(v2);
	}
}