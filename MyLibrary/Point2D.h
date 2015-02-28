#ifndef Point2D_H
#define Point2D_H

class Point2D
{
	public:
		float x, y;
	public:
	

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

		Point2D operator+ (const Point2D& p) const
		{
			Point2D tmp;
			tmp.x = x + p.x;
			tmp.y = y + p.y;

			return tmp;
		}

		Point2D operator- (const Point2D& p) const
		{
			Point2D tmp;
			tmp.x = x - p.x;
			tmp.y = y - p.y;

			return tmp;
		}

		Point2D operator+= (const Point2D& p)
		{
			x += p.x;
			y += p.y;

			return (*this);
		}

		Point2D operator-= (const Point2D& p)
		{
			x -= p.x;
			y -= p.y;

			return (*this);
		}
		
		Point2D operator= (const Point2D& p)
		{
			x = p.x;
			y = p.y;

			return (*this);
		}

		bool operator== (const Point2D& p) const
		{
			return p.x == x && p.y == y;
		}
		
		bool operator!= (const Point2D& p) const
		{
			return p.x != x || p.y != y;
		}

		

	private:

};


#endif