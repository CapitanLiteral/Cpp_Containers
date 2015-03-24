#include "Projectile.h"


Projectile::Projectile()
{
	point = new Point2D<float>();
	speed = new Point2D<float>();

	point->setZero();
	speed->setZero();
}


Projectile::~Projectile()
{
	delete point;
	delete speed;
}


Point2D<float>* Projectile::getCurrentPosition(const float time) const
{
	Point2D<float>* tmp = new Point2D<float>();
	tmp->x = (time*speed->x) + point->x;
	tmp->y = (time*speed->y) + point->y;

	return tmp;
}