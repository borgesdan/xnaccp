#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace Xna {

	class Vector3 {
	public:
		double X { 0 };
		double Y { 0 };
		double Z { 0 };

		Vector3();
		Vector3(double x, double y, double z);

		friend Vector3 operator* (Vector3, Vector3);
	};

}

#endif

