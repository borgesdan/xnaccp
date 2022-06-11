#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <vector>

namespace Xna {

	class Vector2;
	class Vector3;
	class Matrix;

	class Vector4 {
	public:
		double X{ 0 };
		double Y{ 0 };
		double Z{ 0 };
		double W{ 0 };

		Vector4();
		Vector4(double x, double y, double z, double w);
		Vector4(Vector2 value, double z, double w);
		Vector4(Vector3 value, double w);
		Vector4(double value);

		static const Vector4 Zero;
		static const Vector4 One;
		static const Vector4 UnitX;
		static const Vector4 UnitY;
		static const Vector4 UnitZ;
		static const Vector4 UnitW;

		Vector4 operator- (Vector4);
		friend Vector4 operator+ (Vector4, Vector4);
		friend Vector4 operator- (Vector4, Vector4);
		friend Vector4 operator* (Vector4, Vector4);
		friend Vector4 operator* (Vector4, double);
		friend Vector4 operator* (double, Vector4);
		friend Vector4 operator/ (Vector4, Vector4);
		friend Vector4 operator/ (Vector4, double);
		friend bool operator== (Vector4, Vector4);
		friend bool operator!= (Vector4, Vector4);

		static Vector4 Add(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Subtract(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Multiply(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Multiply(Vector4 const& v1, double d);
		static Vector4 Divide(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Divide(Vector4 const& v1, double d);

		static Vector4 Barycentric(Vector4 const& v1, Vector4 const& v2, Vector4 const& v3, double amount1, double amount2);
		static Vector4 CatmullRom(Vector4 const& v1, Vector4 const& v2, Vector4 const& v3, Vector4 const& v4, double amount);
		static Vector4 Ceiling(Vector4 const& v);
		static Vector4 Clamp(Vector4 const& v, Vector4 const& min, Vector4 const& max);
		static double Distance(Vector4 const& v1, Vector4 const& v2);
		static double DistanceSquared(Vector4 const& v1, Vector4 const& v2);
		static double Dot(Vector4 const& v1, Vector4 v2);
		static Vector4 Floor(Vector4 const& v);
		static Vector4 Hermite(Vector4 const& v1, Vector4 const& tan1, Vector4 const& v2, Vector4 tan2, double amount);
		static Vector4 Lerp(Vector4 const& v1, Vector4 const& v2, double amount);
		static Vector4 LerpPrecise(Vector4 const& v1, Vector4 v2, double amount);
		static Vector4 Max(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Min(Vector4 const& v1, Vector4 const& v2);
		static Vector4 Negate(Vector4 const& v);
		static Vector4 Normalize(Vector4 const& v);
		static Vector4 Round(Vector4 const& v);
		static Vector4 SmoothStep(Vector4 const& v1, Vector4 const& v2, double amount);
		
		static Vector4 Transform(Vector2 const& v, Matrix const& m);
		static Vector4 Transform(Vector3 const& v, Matrix const& m);
		static Vector4 Transform(Vector4 const& v, Matrix const& m);
		static bool Transfrom(std::vector<Vector4> const& source, size_t sourceIndex,
			Matrix const& m, std::vector<Vector4>& destination, size_t destinationIndex, size_t length);		
		static bool Transform(std::vector<Vector4> const& source, Matrix const& m, std::vector<Vector4>& destination);

		void Ceiling();
		void Floor();
		double Length() const;
		double LengthSquared() const;
		void Normalize();
		void Round();
		void Deconstruct(double& x, double& y, double& z, double& W) const;
		bool Equals(Vector4 other) const;
	};
}

#endif