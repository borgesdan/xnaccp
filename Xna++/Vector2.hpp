#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <cstdint>
#include <vector>

namespace Xna {

	class Point;
	class Matrix;
	class Quaternion;

	class Vector2 {
	public:
		double X{ 0 };
		double Y{ 0 };

		Vector2();
		Vector2(double, double);
		Vector2(double);
		Vector2(int32_t, int32_t);
		Vector2(Point);

		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 UnitX;
		static const Vector2 UnitY;

		Vector2 operator- (Vector2);
		friend Vector2 operator+ (Vector2, Vector2);
		friend Vector2 operator- (Vector2, Vector2);
		friend Vector2 operator* (Vector2, Vector2);
		friend Vector2 operator* (Vector2, double);
		friend Vector2 operator* (double, Vector2);
		friend Vector2 operator/ (Vector2, Vector2);
		friend Vector2 operator/ (Vector2, double);
		friend Vector2 operator== (Vector2, Vector2);
		friend Vector2 operator!= (Vector2, Vector2);

		static Vector2 Add(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Subtract(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Multiply(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Multiply(Vector2 const& v1, double v2);
		static Vector2 Divide(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Divide(Vector2 const& v1, double v2);

		static Vector2 Barycentric(Vector2 const& v1, Vector2 const& v2, Vector2 const& v3, double amount1, double amount2);
		static Vector2 CatmullRom(Vector2 const& v1, Vector2 const& v2, Vector2 const& v3, Vector2 const& v4, double amount);
		static Vector2 Ceiling(Vector2 const& v);
		static Vector2 Clamp(Vector2 const& v, Vector2 const& min, Vector2 const& max);
		static double Distance(Vector2 const& v1, Vector2 const& v2);
		static double DistanceSquared(Vector2 const& v1, Vector2 const& v2);
		static double Dot(Vector2 const& v1, Vector2 v2);
		static Vector2 Floor(Vector2 const& v);
		static Vector2 Hermite(Vector2 const& v1, Vector2 const& tan1, Vector2 const& v2, Vector2 tan2, double amount);
		static Vector2 Lerp(Vector2 const& v1, Vector2 const& v2, double amount);
		static Vector2 LerpPrecise(Vector2 const& v1, Vector2 v2, double amount);
		static Vector2 Max(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Min(Vector2 const& v1, Vector2 const& v2);
		static Vector2 Negate(Vector2 const& v);
		static Vector2 Normalize(Vector2 const& v);
		static Vector2 Reflect(Vector2 const& v, Vector2 const& normal);
		static Vector2 Round(Vector2 const& v);
		static Vector2 SmoothStep(Vector2 const& v1, Vector2 const& v2, double amount);

		static Vector2 Transform(Vector2 const& positions, Matrix const& m);
		static Vector2 Transform(Vector2 const& v, Quaternion const& q);

		/*
		 O método original Transform e TransformNormal em C# tem o retorno do tipo void e em seu corpo ocorre chamadas a exceções.
		 Esta implementação, ao contrário, retorna false caso ocorra algum erro tratado.
		*/

		static bool Transform(std::vector<Vector2> const& source, size_t sourceIndex,
			Matrix const& m, std::vector<Vector2>& destination, size_t destIndex, size_t length);
		static bool Transform(std::vector<Vector2> const& source, size_t sourceIndex,
			Quaternion const& q, std::vector<Vector2>& destination, size_t destIndex, size_t length);
		static bool Transform(std::vector<Vector2> const& source, Matrix const& m, std::vector<Vector2>& destination);
		static bool Transform(std::vector<Vector2> const& source, Quaternion const& q, std::vector<Vector2>& destination);

		static Vector2 TransformNormal(Vector2 const& normal, Matrix m);
		
		static bool TransformNormal(std::vector<Vector2> const& source, size_t sourceIndex,
			Matrix const& m, std::vector<Vector2>& destination, size_t destIndex, size_t length);
		static bool TransformNormal(std::vector<Vector2> const& source,
			Matrix const& m, std::vector<Vector2>& destination);


		void Ceiling();
		void Floor();
		double Length() const;
		double LengthSquared() const;
		void Normalize();
		void Round();
		Point ToPoint();
		void Deconstruct(double& x, double& y) const;
		bool Equals(Vector2 other) const;
	};
}

#endif
