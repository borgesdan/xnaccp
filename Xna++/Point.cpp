#include "Point.hpp"
#include "Vector2.hpp"

namespace Xna {
	Point::Point() {};
	Point::Point(int32_t value) : X(value), Y(value) {}
	Point::Point(int32_t x, int32_t y) : X(x), Y(y) {}
	Point::Point(Vector2 v) :
		X(static_cast<int32_t>(v.X)),
		Y(static_cast<int32_t>(v.Y)) {}

	const Point Point::Zero = Point();

	Point Point::Add(Point const& p1, Point const& p2) {
		return Point(p1.X + p2.X, p1.Y + p2.Y);
	}

	Point Point::Subtract(Point const& p1, Point const& p2) {
		return Point(p1.X - p2.X, p1.Y - p2.Y);
	}

	Point Point::Multiply(Point const& p1, Point const& p2) {
		return Point(p1.X * p2.X, p1.Y * p2.Y);
	}

	Point Point::Multiply(Point const& p1, int32_t value) {
		return Point(p1.X * value, p1.Y * value);
	}

	Point Point::Divide(Point const& p1, Point const& p2) {
		int32_t x = p2.X != 0 ? p1.X / p2.X : 0;
		int32_t y = p2.Y != 0 ? p1.Y / p2.Y : 0;

		return Point(x, y);
	}

	Point Point::Divide(Point const& p, int32_t v) {
		return v == 0 ? Point() : Point(p.X / v, p.Y / v);
	}

	Point Point::Negate(Point const& p) {
		return Point(-p.X, -p.Y);
	}

	bool Point::Equals(Point const& other) const {
		return X == other.X
			&& Y == other.Y;
	}

	void Point::Deconstruct(int32_t& x, int32_t& y) const{
		x = X;
		y = Y;
	}

	Vector2 Point::ToVector2() const {
		return Vector2(X, Y);
	}	

	Point Point::operator-(Point p) {
		return Point::Negate(p);
	}

	Point operator+ (Point p1, Point p2) {
		return Point::Add(p1, p2);
	}

	Point operator- (Point p1, Point p2) {
		return Point::Subtract(p1, p2);
	}

	Point operator* (Point p1, Point p2) {
		return Point::Multiply(p1, p2);
	}

	Point operator* (Point p, int32_t v) {
		return Point::Multiply(p, v);
	}

	Point operator* (int32_t v, Point p) {
		return Point::Multiply(p, v);
	}

	Point operator/ (Point p1, Point p2) {
		return Point::Divide(p1, p2);
	}

	Point operator/ (Point p, int32_t v) {
		return Point::Divide(p, v);
	}

	Point operator== (Point p1, Point p2) {
		return p1.Equals(p2);
	}

	Point operator!= (Point p1, Point p2) {
		return !p1.Equals(p2);
	}
}