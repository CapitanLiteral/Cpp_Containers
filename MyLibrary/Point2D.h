// Point2D
// 
// Class to operate with points
//

#ifndef Point2D_H
#define Point2D_H

class Point2D
{
	public:
		float x, y;
	public:
	
		Point2D();
		Point2D(float, float);

		void setZero();
		void negate();

		bool isxyZero() const;

		float distanceTo(const Point2D&) const;

		const Point2D& operator+ (const Point2D&) const;
		const Point2D& operator- (const Point2D&) const;
		const Point2D& operator+= (const Point2D&);
		const Point2D& operator-= (const Point2D&);
		const Point2D& operator= (const Point2D);
		bool operator== (const Point2D&) const;		
		bool operator!= (const Point2D&) const;
		

	private:

};


#endif