#include "formes/Triangle.h"
#include <gtest/gtest.h>

const double PI = 3.14159265358979323846;

TEST(Triangle, ConstructeurAvecValeurs) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3(5, 6);

	// Act
	Triangle t(v1, v2, v3);

	// Assert
	EXPECT_EQ(v1, t.p1());
	EXPECT_EQ(v2, t.p2());
	EXPECT_EQ(v3, t.p3());
}

TEST(Triangle, Translation) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3(5, 6);
	Triangle t(v1, v2, v3);

	// Act
	t.translation(Vecteur2D(1, 1));

	// Assert
	EXPECT_EQ(Vecteur2D(2, 3), t.p1());
	EXPECT_EQ(Vecteur2D(4, 5), t.p2());
	EXPECT_EQ(Vecteur2D(6, 7), t.p3());
}

TEST(Triangle, Homothetie) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Vecteur2D v3(5, 6);
	Triangle t(v1, v2, v3);

	// Act
	t.homothetie(Vecteur2D(0, 0), 2);

	// Assert
	EXPECT_EQ(Vecteur2D(2, 4), t.p1());
	EXPECT_EQ(Vecteur2D(6, 8), t.p2());
	EXPECT_EQ(Vecteur2D(10, 12), t.p3());
}

TEST(Triangle, Rotation) {
	// Arrange
	Vecteur2D v1(1, 0);
	Vecteur2D v2(0, 1);
	Vecteur2D v3(0, 0);
	Triangle t(v1, v2, v3);
	const double tolerance = 1e-10;

	// Act
	t.rotation(Vecteur2D(0, 0), PI/2);

	// Assert
	EXPECT_NEAR(0, t.p1().x, tolerance);
	EXPECT_NEAR(1, t.p1().y, tolerance);

	EXPECT_NEAR(-1, t.p2().x, tolerance);
	EXPECT_NEAR(0, t.p2().y, tolerance);

	EXPECT_NEAR(0, t.p3().x, tolerance);
	EXPECT_NEAR(0, t.p3().y, tolerance);
}