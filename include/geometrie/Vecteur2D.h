#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <cmath>
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

	double determinant(const Vecteur2D &u) const
	{
		return x*u.y - y*u.x;
	}

	double norme() const
	{
		return sqrt(normeCarree());
	}

	double normeCarree() const
	{
		return x*x + y*y;
	}

	const Vecteur2D operator + (const double &a) const;

	const Vecteur2D operator + (const Vecteur2D &u) const;

	const Vecteur2D& operator += (const Vecteur2D &u);

	const Vecteur2D operator - () const;

	const Vecteur2D operator - (const Vecteur2D &u) const;

	const Vecteur2D operator * (const double &a) const;

	const Vecteur2D operator * (const Vecteur2D &u) const;

	operator string() const;

}; // class Vecteur2D

inline const Vecteur2D Vecteur2D::operator + (const double &a) const
{
	return Vecteur2D(x+a, y+a);
}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D &u) const
{
	return Vecteur2D(x+u.x, y+u.y);
}

inline const Vecteur2D& Vecteur2D::operator += (const Vecteur2D &u)
{
	x += u.x;
	y += u.y;
	return *this;
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

inline const Vecteur2D Vecteur2D::operator - (const Vecteur2D &u) const
{
	return Vecteur2D(x-u.x, y-u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double &a) const
{
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator * (const Vecteur2D &u) const
{
	return Vecteur2D(x*u.x, y*u.y);
}

inline Vecteur2D::operator string() const
{
	ostringstream oss;
	oss << "( " << x << ", " << y << ")";
	return oss.str();
}

inline ostream& operator << (ostream& os, const Vecteur2D &v)
{
	return os << string(v);
}

#endif // VECTEUR2D_H