#ifndef _POINT_H_
#define _POINT_H_

#include <cstdint>

namespace Xna {

	class Vector2;

	class Point {
	public:
		int32_t X{ 0 };
		int32_t Y{ 0 };

		Point();
		Point(int32_t value);
		Point(int32_t x, int32_t y);
		Point(Vector2 v);

		static const Point Zero;

		Point operator- (Point);
		friend Point operator+ (Point, Point);
		friend Point operator- (Point, Point);
		friend Point operator* (Point, Point);
		friend Point operator* (Point, int32_t);
		friend Point operator* (int32_t, Point);
		friend Point operator/ (Point, Point);
		friend Point operator/ (Point, int32_t);
		friend Point operator== (Point, Point);
		friend Point operator!= (Point, Point);

		static Point Add(Point const&, Point const&);
		static Point Subtract(Point const&, Point const&);
		static Point Multiply(Point const&, Point const&);
		static Point Multiply(Point const&, int32_t);
		//Retorna X ou Y igual a 0 caso algum valor do segundo parâmetro seja 0.
		static Point Divide(Point const&, Point const&);
		static Point Divide(Point const&, int32_t);
		static Point Negate(Point const&);

		bool Equals(Point const& other) const;
		void Deconstruct(int32_t& x, int32_t& y) const;
		Vector2 ToVector2() const;
	};
}

#endif