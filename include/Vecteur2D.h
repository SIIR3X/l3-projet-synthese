#pragma once

#include <string>
#include <sstream>

using namespace std;

class Vecteur2D
{
public:
	double x;
	double y;

	explicit Vecteur2D(const double &x = 0, const double &y = 0)
		: x(x), y(y) {}

	inline double determinant(const Vecteur2D &u) const;

	inline const Vecteur2D operator + (const double &a) const;

	inline const Vecteur2D operator - () const;

	inline const Vecteur2D operator * (const double &a) const;

	inline operator string() const;

	friend ostream& operator << (ostream &os, const Vecteur2D &u)
	{
		return os << string(u);
	}
}; // class Vecteur2D

double Vecteur2D::determinant(const Vecteur2D &u) const
{
	return x*u.y - y*u.x;
}

const Vecteur2D Vecteur2D::operator + (const double &a) const
{
	return Vecteur2D(x+a, y+a);
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

const Vecteur2D Vecteur2D::operator * (const double &a) const
{
	return Vecteur2D(x*a, y*a);
}

Vecteur2D::operator string() const
{
	ostringstream oss;
	oss << "(" << x << ", " << y << ")";
	return oss.str();
}