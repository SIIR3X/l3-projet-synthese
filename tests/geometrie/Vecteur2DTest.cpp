#include "geometrie/Vecteur2D.h"
#include <gtest/gtest.h>

TEST(Vecteur2D, ConstructeurParDefaut) {
	Vecteur2D v;
	EXPECT_EQ(0, v.x);
	EXPECT_EQ(0, v.y);
}

TEST(Vecteur2D, Constructeur)
{
	Vecteur2D v(1, 2);
	EXPECT_EQ(1, v.x);
	EXPECT_EQ(2, v.y);
}

TEST(Vecteur2D, Determinant)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	EXPECT_EQ(-2, v1.determinant(v2));
}

TEST(Vecteur2D, Norme)
{
	Vecteur2D v(3, 4);
	EXPECT_EQ(5, v.norme());
}

TEST(Vecteur2D, NormeCarree)
{
	Vecteur2D v(3, 4);
	EXPECT_EQ(25, v.normeCarree());
}

TEST(Vecteur2D, AdditionScalaire)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2 = v1 + 3;
	EXPECT_EQ(4, v2.x);
	EXPECT_EQ(5, v2.y);
}

TEST(Vecteur2D, AdditionVecteur)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3 = v1 + v2;
	EXPECT_EQ(4, v3.x);
	EXPECT_EQ(6, v3.y);
}

TEST(Vecteur2D, AdditionVecteurAvecAffectation)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	v1 += v2;
	EXPECT_EQ(4, v1.x);
	EXPECT_EQ(6, v1.y);
}

TEST(Vecteur2D, Oppose)
{
	Vecteur2D v(1, 2);
	Vecteur2D w = -v;
	EXPECT_EQ(-1, w.x);
	EXPECT_EQ(-2, w.y);
}

TEST(Vecteur2D, Soustraction)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3 = v1 - v2;
	EXPECT_EQ(-2, v3.x);
	EXPECT_EQ(-2, v3.y);
}

TEST(Vecteur2D, MultiplicationScalaire)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2 = v1 * 3;
	EXPECT_EQ(3, v2.x);
	EXPECT_EQ(6, v2.y);
}

TEST(Vecteur2D, MultiplicationVecteur)
{
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3 = v1 * v2;
	EXPECT_EQ(3, v3.x);
	EXPECT_EQ(8, v3.y);
}