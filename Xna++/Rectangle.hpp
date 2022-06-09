#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <cstdint>

namespace Xna {

	class Point;
	class Vector2;

	class Rectangle {
	public:
		int32_t X{ 0 };
		int32_t Y{ 0 };
		int32_t Width{ 0 };
		int32_t Height{ 0 };

		Rectangle();
		Rectangle(int32_t x, int32_t y, int32_t width, int32_t height);
		Rectangle(Point location, Point size);
		Rectangle(Vector2 location, Vector2 size);

		static const Rectangle Empty;		

		friend bool operator== (Rectangle, Rectangle);
		friend bool operator!= (Rectangle, Rectangle);

		static Rectangle Intersect(Rectangle v1, Rectangle v2);
		static Rectangle Union(Rectangle v1, Rectangle v2);

		int32_t Left() const;
		int32_t Right() const;
		int32_t Top() const;
		int32_t Bottom() const;
		bool IsEmpty() const;
		Point Location() const;
		Point Size() const;
		Point Center() const;
		bool Contains(int32_t x, int32_t y) const;
		bool Contains(double x, double y) const;
		bool Contains(Point value) const;
		bool Contains(Vector2 value) const;
		bool Contains(Rectangle value) const;
		bool Equals(Rectangle other) const;
		void Inflate(int32_t horizontal, int32_t vertical);
		void Inflate(double horizontal, double vertical);
		bool Intersects(Rectangle other) const;
		void Offset(int32_t x, int32_t y);
		void Offset(double x, double y);
		void Offset(Point p);
		void Offset(Vector2 v);
		void Deconstruct(int32_t& x, int32_t& y, int32_t& width, int32_t& height) const;
	};
}

#endif