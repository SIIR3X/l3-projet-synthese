#include "formes/Segment.h"
#include <gtest/gtest.h>

const double PI = 3.14159265358979323846;

TEST(Segment, ConstructeurAvecValeurs) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);

	// Act
	Segment s(v1, v2);

	// Assert
	EXPECT_EQ(v1, s.p1());
	EXPECT_EQ(v2, s.p2());
}

TEST(Segment, Translation) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Segment s(v1, v2);

	// Act
	s.translation(Vecteur2D(1, 1));

	// Assert
	EXPECT_EQ(Vecteur2D(2, 3), s.p1());
	EXPECT_EQ(Vecteur2D(4, 5), s.p2());
}

TEST(Segment, Homothetie) {
	// Arrange
	Vecteur2D v1(1, 2);
	Vecteur2D v2(3, 4);
	Segment s(v1, v2);

	// Act
	s.homothetie(Vecteur2D(0, 0), 2);

	// Assert
	EXPECT_EQ(Vecteur2D(2, 4), s.p1());
	EXPECT_EQ(Vecteur2D(6, 8), s.p2());
}

TEST(Segment, Rotation) {
	// Arrange
	Vecteur2D v1(1, 0);
	Vecteur2D v2(0, 1);
	Segment s(v1, v2);
	const double tolerance = 1e-10;

	// Act
	s.rotation(Vecteur2D(0, 0), PI/2);


	// Assert
	EXPECT_NEAR(0, s.p1().x, tolerance);
	EXPECT_NEAR(1, s.p1().y, tolerance);
	EXPECT_NEAR(-1, s.p2().x, tolerance);
	EXPECT_NEAR(0, s.p2().y, tolerance);
}