#pragma once
#include "Point2D.h"
class Projectile 
{
public:

	Point2D<float>* point;
	Point2D<float>* speed;

	Projectile();
	~Projectile();

	Point2D<float>* getCurrentPosition(const float time) const;
};

