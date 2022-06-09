#include <algorithm>
#include "Rectangle.hpp"
#include "Point.hpp"
#include "Vector2.hpp"

namespace Xna {
	Rectangle::Rectangle() {}
	Rectangle::Rectangle(int32_t x, int32_t y, int32_t width, int32_t height) :
		X(x), Y(y), Width(width), Height(height) {}
	Rectangle::Rectangle(Point location, Point size) :
		X(location.X), Y(location.Y), Width(size.X), Height(size.Y) {}
	Rectangle::Rectangle(Vector2 location, Vector2 size) :
		X(static_cast<int32_t>(location.X)),
		Y(static_cast<int32_t>(location.Y)),
		Width(static_cast<int32_t>(size.X)),
		Height(static_cast<int32_t>(size.Y)) {}

	const Rectangle Rectangle::Empty = Rectangle();

	Rectangle Rectangle::Intersect(Rectangle v1, Rectangle v2) {
		if (v1.Intersects(v2))
		{
			int right_side = std::min(v1.X + v1.Width, v2.X + v2.Width);
			int left_side = std::max(v1.X, v2.X);
			int top_side = std::max(v1.Y, v2.Y);
			int bottom_side = std::min(v1.Y + v1.Height, v2.Y + v2.Height);
			
			return Rectangle(
				left_side, 
				top_side,
				right_side - left_side,
				bottom_side - top_side
			);
		}

		return Rectangle(0, 0, 0, 0);
	}
	
	Rectangle Rectangle::Union(Rectangle v1, Rectangle v2) {
		int32_t x = std::min(v1.X, v2.X);
		int32_t y = std::min(v1.Y, v2.Y);
		
		return Rectangle(x, y,
			std::max(v1.Right(), v2.Right()) - x,
			std::max(v1.Bottom(), v2.Bottom()) - y
		);
	}

	int32_t Rectangle::Left() const {
		return X;
	}

	int32_t Rectangle::Right() const {
		return X + Width;
	}

	int32_t Rectangle::Top() const {
		return Y;
	}

	int32_t Rectangle::Bottom() const {
		return Y + Height;
	}

	bool Rectangle::IsEmpty() const {
		return X == 0
			&& Y == 0
			&& Width == 0
			&& Height == 0;
	}

	Point Rectangle::Location() const {
		return Point(X, Y);
	}

	Point Rectangle::Size() const {
		return Point(Width, Height);
	}

	Point Rectangle::Center() const {
		return Point(X + (Width / 2), Y + (Height / 2));
	}

	bool Rectangle::Contains(int32_t x, int32_t y) const {
		return X <= x 
			&& x < (X + Width)
			&& Y <= y
			&& y < (Y + Height);
	}

	bool Rectangle::Contains(double x, double y) const {
		return Rectangle::Contains(static_cast<int32_t>(x), static_cast<int32_t>(y));
	}

	bool Rectangle::Contains(Point value) const {
		return Rectangle::Contains(value.X, value.Y);
	}

	bool Rectangle::Contains(Vector2 value) const {
		return Rectangle::Contains(value.X, value.Y);
	}

	bool Rectangle::Contains(Rectangle value) const {
		return X <= value.X
			&& (value.X + value.Width) <= (X + Width)
			&& Y <= value.Y
			&& (value.Y + value.Height) <= (Y + Height);
	}

	bool Rectangle::Equals(Rectangle other) const {
		return X == other.X
			&& Y == other.Y
			&& Width == other.Width
			&& Height == other.Height;
	}

	void Rectangle::Inflate(int32_t horizontal, int32_t vertical) {
		X -= horizontal;
		Y -= vertical;
		Width += horizontal * 2;
		Height += vertical * 2;
	}

	void Rectangle::Inflate(double horizontal, double vertical) {
		Rectangle::Inflate(static_cast<int32_t>(horizontal), static_cast<int32_t>(vertical));
	}

	bool Rectangle::Intersects(Rectangle other) const {
		return other.Left() < Right() 
			&& Left() < other.Right()
			&& other.Top() < Bottom()
			&& Top() < other.Bottom();
	}

	void Rectangle::Offset(int32_t x, int32_t y) {
		X += x;
		Y += y;
	}

	void Rectangle::Offset(double x, double y) {
		Rectangle::Offset(static_cast<int32_t>(x), static_cast<int32_t>(y));
	}

	void Rectangle::Offset(Point p) {
		Rectangle::Offset(p.X, p.Y);
	}

	void Rectangle::Offset(Vector2 v) {
		Rectangle::Offset(v.X, v.Y);
	}

	void Rectangle::Deconstruct(int32_t& x, int32_t& y, int32_t& width, int32_t& height) const {
		x = X;
		y = Y;
		width = Width;
		height = Height;
	}

	bool operator== (Rectangle r1, Rectangle r2) {
		return r1.Equals(r2);
	}
	
	bool operator!= (Rectangle r1, Rectangle r2) {
		return !r1.Equals(r2);
	}
}