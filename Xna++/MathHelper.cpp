#include "MathHelper.hpp"
#include <cmath>

namespace Xna {	

	double MathHelper::Barycentric(double v1, double v2, double v3, double amount1, double amount2) {
		return v1 + (v2 - v1) * amount1 + (v3 - v1) * amount2;
	}

	double MathHelper::CatmullRom(double v1, double v2, double v3, double v4, double amount) {
		double amountSquared = amount * amount;
		double amountCubed = amountSquared * amount;

		return (0.5 * (2.0 * v2 +
			(v3 - v1) * amount +
			(2.0 * v1 - 5.0 * v2 + 4.0 * v3 - v4) * amountSquared +
			(3.0 * v2 - v1 - 3.0 * v3 + v4) * amountCubed));
	}

	double MathHelper::Clamp(double v, double min, double max) {
		v = (v > max) ? max : v;
		v = (v < min) ? min : v;
		return v;
	}

	int32_t MathHelper::Clamp(int32_t v, int32_t min, int32_t max) {
		v = (v > max) ? max : v;
		v = (v < min) ? min : v;
		return v;
	}

	double MathHelper::Distance(double v1, double v2) {
		return abs(v1 - v2);
	}

	double MathHelper::Hermite(double v1, double tan1, double v2, double tan2, double amount) {
		double result;
		double aCubed = amount * amount * amount;
		double aSquared = amount * amount;

		if (amount == 0.0) {
			result = v1;
		}
		else if (amount == 1.0) {
			result = v2;
		}
		else {
			result = (2 * v1 - 2 * v2 + tan2 + tan1) * aCubed +
				(3 * v2 - 3 * v1 - 2 * tan1 - tan2) * aSquared +
				tan1 * amount +
				v1;
		}
	}

	double MathHelper::Lerp(double v1, double v2, double amount) {
		return v1 + (v2 - v1) * amount;
	}

	double MathHelper::LerpPrecise(double v1, double v2, double amount) {
		return ((1.0 - amount) * v1) + (v2 * amount);
	}

	double MathHelper::Max(double v1, double v2) {
		return v1 > v2 ? v1 : v2;
	}

	int32_t MathHelper::Max(int32_t v1, int32_t v2) {
		return v1 > v2 ? v1 : v2;
	}

	double MathHelper::Min(double v1, double v2) {
		return v1 < v2 ? v1 : v2;
	}

	int32_t MathHelper::Min(int32_t v1, int32_t v2) {
		return v1 < v2 ? v1 : v2;
	}

	double MathHelper::SmoothStep(double v1, double v2, double amount) {
		double result = Clamp(amount, 0.0, 1.0);
		result = Hermite(v1, 0.0, v2, 0.0, result);

		return result;
	}

	double MathHelper::ToDegrees(double radians) {
		return radians * 57.295779513082320876798154814105;
	}

	double MathHelper::ToRadians(double degrees) {
		return degrees * 0.017453292519943295769236907684886;
	}

	double MathHelper::WrapAngle(double angle) {
		if ((angle > -PI) && (angle <= PI)) {
			return angle;
		}

		angle = fmod(angle, TWO_PI);

		if (angle <= -PI) {
			return angle + TWO_PI;
		}

		if (angle > PI) {
			return angle - TWO_PI;
		}

		return angle;
	}

	bool MathHelper::IsPowerOfTwo(int32_t v) {
		return (v > 0) && ((v & (v - 1)) == 0);
	}

	double MathHelper::Sign(double v) {
		if (v < 0) {
			return -1;
		}

		return v > 0 ? 1 : 0;
	}
}