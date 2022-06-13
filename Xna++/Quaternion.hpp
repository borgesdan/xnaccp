#ifndef _QUATERNION_H_
#define _QUATERNION_H_

namespace Xna {

	class Vector3;
	class Vector4;
	class Matrix;

	class Quaternion {
	public:
		double X{ 0 };
		double Y{ 0 };
		double Z{ 0 };
		double W{ 0 };

		Quaternion();
		Quaternion(Vector4 value);
		Quaternion(Vector3 value, double w);
		Quaternion(double value);
		Quaternion(double x, double y, double z, double w);

		static const Quaternion Identity;

		Quaternion operator- (Quaternion);
		friend Quaternion operator+ (Quaternion, Quaternion);
		friend Quaternion operator- (Quaternion, Quaternion);
		friend Quaternion operator* (Quaternion, Quaternion);
		friend Quaternion operator* (Quaternion, double);
		friend Quaternion operator* (double, Quaternion);
		friend Quaternion operator/ (Quaternion, Quaternion);
		friend bool operator== (Quaternion, Quaternion);
		friend bool operator!= (Quaternion, Quaternion);

		static Quaternion Add(Quaternion const& q1, Quaternion const& q2);
		static Quaternion Subtract(Quaternion const& q1, Quaternion const& q2);
		static Quaternion Multiply(Quaternion const& q1, Quaternion const& q2);
		static Quaternion Multiply(Quaternion const& q1, double d);
		static Quaternion Divide(Quaternion const& q1, Quaternion const& q2);

		static Quaternion Concatenate(Quaternion const& q1, Quaternion const& q2);
		static Quaternion Conjugate(Quaternion const& q);
		static Quaternion CreateFromAxisAngle(Vector3 const& axis, double angle);
		static Quaternion CreateFromRotationMatrix(Matrix m);
		static Quaternion CreateFromYawPitchRoll(double yaw, double pitch, double roll);
		static double Dot(Quaternion const& q1, Quaternion const& q2);
		static Quaternion Inverse(Quaternion const& q);
		static Quaternion Lerp(Quaternion const& q1, Quaternion const& q2, double d);
		static Quaternion SLerp(Quaternion const& q1, Quaternion const& q2, double d);
		static Quaternion Negate(Quaternion const& q);
		static Quaternion Normalize(Quaternion const& q);

		void Conjugate();
		bool Equals(Quaternion other);
		double Length();
		double LengthSquared();
		void Normalize();
		void Deconstruct(double& x, double& y, double& z, double& w);
	};
}

#endif
