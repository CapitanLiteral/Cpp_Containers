// Point2D


#include "Point2D.h"
#include "Math.h"


Point2D::Point2D()
{
	setZero();
}
Point2D::Point2D(float _x, float _y)
{
	x = _x;
	y = _y;
}

float Point2D::distanceTo(const Point2D& p) const
{
	return fabsf(sqrtf(powf((p.x - x), 2) + powf((p.y - y), 2)));
}

void Point2D::setZero()
{
	x = y = 0.0f;
}
bool Point2D::isxyZero() const
{
	return x == 0 && y == 0;
}
void Point2D::negate()
{
	x = -x;
	y = -y;
}

const Point2D& Point2D::operator+ (const Point2D& p) const
{
	Point2D tmp;
	tmp.x = x + p.x;
	tmp.y = y + p.y;

	return tmp;
}
const Point2D& Point2D::operator- (const Point2D& p) const
{
	Point2D tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;

	return tmp;
}
const Point2D& Point2D::operator+= (const Point2D& p)
{
	x += p.x;
	y += p.y;

	return (*this);
}
const Point2D& Point2D::operator-= (const Point2D& p)
{
	x -= p.x;
	y -= p.y;

	return (*this);
}
const Point2D& Point2D::operator= (const Point2D p)
{
	x = p.x;
	y = p.y;

	return (*this);
}
bool Point2D::operator== (const Point2D& p) const
{
	return p.x == x && p.y == y;
}
bool Point2D::operator!= (const Point2D& p) const
{
	return p.x != x || p.y != y;
}