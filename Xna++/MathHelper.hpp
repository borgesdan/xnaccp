#ifndef _MATHHELPER_H_
#define _MATHHELPER_H_

#include <cstdint>

namespace Xna {

	class MathHelper {
		static constexpr double LOG10E = 0.434294481903251827651;
		static constexpr double LOG10E = 0.434294481903251827651;
		static constexpr double PI = 3.14159265358979323846;
		static constexpr double PI_OVER_2 = 1.57079632679489661923;
		static constexpr double PI_OVER_4 = 0.785398163397448309616;
		static constexpr double TWO_PI = PI * 2.0;
		static constexpr double TAU = TWO_PI;

		static double Barycentric(double v1, double v2, double v3, double amount1, double amount2);
		static double CatmullRom(double v1, double v2, double v3, double v4, double amount);
		static double Clamp(double v, double min, double max);
		static int32_t Clamp(int32_t v, int32_t min, int32_t max);
		static double Distance(double v1, double v2);
		static double Hermite(double v1, double tan1, double v2, double tan2, double amount);
		static double Lerp(double v1, double v2, double amount);
		static double LerpPrecise(double v1, double v2, double amount);
		static double Max(double v1, double v2);
		static int32_t Max(int32_t v1, int32_t v2);
		static double Min(double v1, double v2);
		static int32_t Min(int32_t v1, int32_t v2);
		static double SmoothStep(double v1, double v2, double amount);
		static double ToDegrees(double radians);
		static double ToRadians(double degrees);
		static double WrapAngle(double angle);
		static bool IsPowerOfTwo(int32_t v);
		//Returns - 1, 0, or 1 if the sign of the number is negative, 0, or positive.
		static double Sign(double v);
	};
}

#endif
