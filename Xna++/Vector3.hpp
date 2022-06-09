#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace Xna {

	class Vector2;
	class Matrix;
	class Quaternion;

	class Vector3 {
	public:
		double X { 0 };
		double Y { 0 };
		double Z { 0 };

		Vector3();
		Vector3(double x, double y, double z);
		Vector3(double value);
		Vector3(Vector2 value, double z);

		static const Vector3 Zero;
		static const Vector3 One;
		static const Vector3 UnitX;
		static const Vector3 UnitY;
		static const Vector3 UnitZ;
		static const Vector3 Up;
		static const Vector3 Down;
		static const Vector3 Right;
		static const Vector3 Left;
		static const Vector3 Forward;
		static const Vector3 Backward;

		Vector3 operator- (Vector3);
		friend Vector3 operator+ (Vector3, Vector3);
		friend Vector3 operator- (Vector3, Vector3);
		friend Vector3 operator* (Vector3, Vector3);
		friend Vector3 operator* (Vector3, double);
		friend Vector3 operator* (double, Vector3);
		friend Vector3 operator/ (Vector3, Vector3);
		friend Vector3 operator/ (Vector3, double);
		friend Vector3 operator== (Vector3, Vector3);
		friend Vector3 operator!= (Vector3, Vector3);

		static Vector3 Add(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Subtract(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Multiply(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Multiply(Vector3 const& v1, double d);
		static Vector3 Divide(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Divide(Vector3 const& v1, double d);

		static Vector3 Barycentric(Vector3 const& v1, Vector3 const& v2, Vector3 const& v3, double amount1, double amount2);
		static Vector3 CatmullRom(Vector3 const& v1, Vector3 const& v2, Vector3 const& v3, Vector3 const& v4, double amount);
		static Vector3 Ceiling(Vector3 const& v);
		static Vector3 Clamp(Vector3 const& v, Vector3 const& min, Vector3 const& max);
		static Vector3 Cross(Vector3 const& v1, Vector3 const& v2);
		static double Distance(Vector3 const& v1, Vector3 const& v2);
		static double DistanceSquared(Vector3 const& v1, Vector3 const& v2);
		static double Dot(Vector3 const& v1, Vector3 v2);
		static Vector3 Floor(Vector3 const& v);
		static Vector3 Hermite(Vector3 const& v1, Vector3 const& tan1, Vector3 const& v2, Vector3 tan2, double amount);
		static Vector3 Lerp(Vector3 const& v1, Vector3 const& v2, double amount);
		static Vector3 LerpPrecise(Vector3 const& v1, Vector3 v2, double amount);
		static Vector3 Max(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Min(Vector3 const& v1, Vector3 const& v2);
		static Vector3 Negate(Vector3 const& v);
		static Vector3 Normalize(Vector3 const& v);
		static Vector3 Reflect(Vector3 const& v, Vector3 const& normal);
		static Vector3 Round(Vector3 const& v);
		static Vector3 SmoothStep(Vector3 const& v1, Vector3 const& v2, double amount);

		static Vector3 Transform(Vector3 const& positions, Matrix const& m);
		static Vector3 Transform(Vector3 const& v, Quaternion const& q);

		static bool Transform(std::vector<Vector3> const& source, size_t sourceIndex,
			Matrix const& m, std::vector<Vector3>& destination, size_t destIndex, size_t length);
		static bool Transform(std::vector<Vector3> const& source, size_t sourceIndex,
			Quaternion const& q, std::vector<Vector3>& destination, size_t destIndex, size_t length);
		
		static bool Transform(std::vector<Vector3> const& source, Matrix const& m, std::vector<Vector3>& destination);
		static bool Transform(std::vector<Vector3> const& source, Quaternion const& q, std::vector<Vector3>& destination);

		static Vector3 TransformNormal(Vector3 const& normal, Matrix m);

		static bool TransformNormal(std::vector<Vector3> const& source, size_t sourceIndex,
			Matrix const& m, std::vector<Vector3>& destination, size_t destIndex, size_t length);
		static bool TransformNormal(std::vector<Vector3> const& source,
			Matrix const& m, std::vector<Vector3>& destination);

		void Ceiling();
		void Floor();
		double Length() const;
		double LengthSquared() const;
		void Normalize();
		void Round();
		void Deconstruct(double& x, double& y) const;
		bool Equals(Vector3 other) const;
	};

}

#endif

