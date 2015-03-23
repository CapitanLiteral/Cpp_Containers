// Point2D
// 
// Class to operate with points
//

#ifndef Point2D_H
#define Point2D_H

#include "Math.h"

template <class TYPE>
class Point2D
{
	public:
		TYPE x, y;
	
		/*Point2D();
		Point2D(TYPE, TYPE);*/


		Point2D()
		{
			setZero();
		}
		Point2D(TYPE _x, TYPE _y)
		{
			x = _x;
			y = _y;
		}

		/*TYPE distanceTo(const Point2D& p) const // This gona blow up if TYPE isn't a float
		{
			return fabsf(sqrtf(powf((p.x - x), 2) + powf((p.y - y), 2)));
		}*/
		// Copied from ricard sample --- Start
		TYPE distanceTo(const Point2D& v) const
		{
			TYPE fx = x - v.x;
			TYPE fy = y - v.y;

			return sqrt((fx*fx) + (fy*fy));
		}
		// Copied from ricard sample --- End
		void setZero()
		{
			x = y = 0.0f;
		}
		bool isxyZero() const
		{
			return x == 0 && y == 0;
		}
		void negate()
		{
			x = -x;
			y = -y;
		}

		const Point2D& operator+ (const Point2D& p) const
		{
			Point2D tmp;
			tmp.x = x + p.x;
			tmp.y = y + p.y;

			return tmp;
		}
		const Point2D& operator- (const Point2D& p) const
		{
			Point2D tmp;
			tmp.x = x - p.x;
			tmp.y = y - p.y;

			return tmp;
		}
		const Point2D& operator+= (const Point2D& p)
		{
			x += p.x;
			y += p.y;

			return (*this);
		}
		const Point2D& operator-= (const Point2D& p)
		{
			x -= p.x;
			y -= p.y;

			return (*this);
		}
		/*const Point2D& operator= (const Point2D p)
		{
		x = p.x;
		y = p.y;

		return (*this);
		}*/
		bool operator== (const Point2D& p) const
		{
			return p.x == x && p.y == y;
		}
		bool operator!= (const Point2D& p) const
		{
			return p.x != x || p.y != y;
		}

		/*void setZero();
		void negate();

		bool isxyZero() const;

		float distanceTo(const Point2D&) const;

		const Point2D& operator+ (const Point2D&) const;
		const Point2D& operator- (const Point2D&) const;
		const Point2D& operator+= (const Point2D&);
		const Point2D& operator-= (const Point2D&);
		//const Point2D& operator= (const Point2D);
		bool operator== (const Point2D&) const;		
		bool operator!= (const Point2D&) const;*/
		

};


#endif