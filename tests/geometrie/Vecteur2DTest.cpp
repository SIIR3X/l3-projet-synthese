#include "geometrie/Vecteur2D.h"
#include <gtest/gtest.h>

TEST(Vecteur2D, ConstructeurParDefaut) {
	// Arrange
	Vecteur2D v;

	// Assert
	EXPECT_EQ(0, v.x);
	EXPECT_EQ(0, v.y);
}

TEST(Vecteur2D, ConstructeurAvecValeurs)
{
	// Arrange
	Vecteur2D v(1, 2);

	// Assert
	EXPECT_EQ(1, v.x);
	EXPECT_EQ(2, v.y);
}

TEST(Vecteur2D, Determinant)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	double d = v1.determinant(v2);
	
	// Assert
	EXPECT_EQ(-2, d);
}

TEST(Vecteur2D, Norme)
{
	// Arrange
	Vecteur2D v(3, 4);

	// Act
	double n = v.norme();

	// Assert
	EXPECT_EQ(5, n);
}

TEST(Vecteur2D, NormeCarree)
{
	// Arrange
	Vecteur2D v(3, 4);

	// Act
	double n = v.normeCarree();

	// Assert
	EXPECT_EQ(25, n);
}

TEST(Vecteur2D, AdditionScalaire)
{
	// Arrange
	Vecteur2D v(1, 2);

	// Act
	Vecteur2D w = v + 3;

	// Assert
	EXPECT_EQ(4, w.x);
}

TEST(Vecteur2D, AdditionVecteur)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	Vecteur2D v3 = v1 + v2;

	// Assert
	EXPECT_EQ(4, v3.x);
	EXPECT_EQ(6, v3.y);
}

TEST(Vecteur2D, AdditionVecteurAvecAffectation)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	v1 += v2;

	// Assert
	EXPECT_EQ(4, v1.x);
	EXPECT_EQ(6, v1.y);
}

TEST(Vecteur2D, Oppose)
{
	// Arrange
	Vecteur2D v(1, 2);

	// Act
	Vecteur2D w = -v;

	// Assert
	EXPECT_EQ(-1, w.x);
	EXPECT_EQ(-2, w.y);
}

TEST(Vecteur2D, Soustraction)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	Vecteur2D v3 = v1 - v2;

	// Assert
	EXPECT_EQ(-2, v3.x);
	EXPECT_EQ(-2, v3.y);
}

TEST(Vecteur2D, MultiplicationScalaire)
{
	// Arrange
	Vecteur2D v(1, 2);

	// Act
	Vecteur2D w = v * 3;

	// Assert
	EXPECT_EQ(3, w.x);
	EXPECT_EQ(6, w.y);
}

TEST(Vecteur2D, MultiplicationVecteur)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	Vecteur2D v3 = v1 * v2;

	// Assert
	EXPECT_EQ(3, v3.x);
	EXPECT_EQ(8, v3.y);
}

TEST(Vecteur2D, Comparaison)
{
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(1, 2);
	Vecteur2D v3(3, 4);

	// Assert
	EXPECT_TRUE(v1 == v2);
	EXPECT_FALSE(v1 == v3);
}