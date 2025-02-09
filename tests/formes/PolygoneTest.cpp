#include "formes/Polygone.h"
#include <gtest/gtest.h>

const double PI = 3.14159265358979323846;

TEST(Polygone, ConstructeurAvecValeurs) {
    // Arrange
    Vecteur2D v1(1, 2);
    Vecteur2D v2(3, 4);
    Vecteur2D v3(5, 6);
    Vecteur2D v4(7, 8);
    Vecteur2D v5(9, 10);
    Vecteur2D v6(11, 12);
    Polygone p({v1, v2, v3, v4, v5, v6});

    // Act
    // Assert
    EXPECT_EQ(v1, p.points()[0]);
    EXPECT_EQ(v2, p.points()[1]);
    EXPECT_EQ(v3, p.points()[2]);
    EXPECT_EQ(v4, p.points()[3]);
    EXPECT_EQ(v5, p.points()[4]);
    EXPECT_EQ(v6, p.points()[5]);
}

TEST(Polygone, Translation) {
    // Arrange
    Vecteur2D v1(1, 2);
    Vecteur2D v2(3, 4);
    Vecteur2D v3(5, 6);
    Vecteur2D v4(7, 8);
    Vecteur2D v5(9, 10);
    Vecteur2D v6(11, 12);
    Polygone p({v1, v2, v3, v4, v5, v6});

    // Act
    p.translation(Vecteur2D(1, 1));

    // Assert
    EXPECT_EQ(Vecteur2D(2, 3), p.points()[0]);
    EXPECT_EQ(Vecteur2D(4, 5), p.points()[1]);
    EXPECT_EQ(Vecteur2D(6, 7), p.points()[2]);
    EXPECT_EQ(Vecteur2D(8, 9), p.points()[3]);
    EXPECT_EQ(Vecteur2D(10, 11), p.points()[4]);
    EXPECT_EQ(Vecteur2D(12, 13), p.points()[5]);
}

TEST(Polygone, Homothetie) {
    // Arrange
    Vecteur2D v1(1, 2);
    Vecteur2D v2(3, 4);
    Vecteur2D v3(5, 6);
    Vecteur2D v4(7, 8);
    Vecteur2D v5(9, 10);
    Vecteur2D v6(11, 12);
    Polygone p({v1, v2, v3, v4, v5, v6});

    // Act
    p.homothetie(Vecteur2D(0, 0), 2);

    // Assert
    EXPECT_EQ(Vecteur2D(2, 4), p.points()[0]);
    EXPECT_EQ(Vecteur2D(6, 8), p.points()[1]);
    EXPECT_EQ(Vecteur2D(10, 12), p.points()[2]);
    EXPECT_EQ(Vecteur2D(14, 16), p.points()[3]);
    EXPECT_EQ(Vecteur2D(18, 20), p.points()[4]);
    EXPECT_EQ(Vecteur2D(22, 24), p.points()[5]);
}

TEST(Polygone, Rotation) {
    // Arrange
    Vecteur2D v1(1, 0);
    Vecteur2D v2(0, 1);
    Vecteur2D v3(-1, 0);
    Vecteur2D v4(0, -1);
    Vecteur2D v5(1, 0);
    Vecteur2D v6(0, 1);
    Polygone p({v1, v2, v3, v4, v5, v6});
    const double tolerance = 1e-10;

    // Act
    p.rotation(Vecteur2D(0, 0), PI/2);

    // Assert
    EXPECT_NEAR(0, p.points()[0].x, tolerance);
    EXPECT_NEAR(1, p.points()[0].y, tolerance);
    
    EXPECT_NEAR(-1, p.points()[1].x, tolerance);
    EXPECT_NEAR(0, p.points()[1].y, tolerance);
    
    EXPECT_NEAR(0, p.points()[2].x, tolerance);
    EXPECT_NEAR(-1, p.points()[2].y, tolerance);
    
    EXPECT_NEAR(1, p.points()[3].x, tolerance);
    EXPECT_NEAR(0, p.points()[3].y, tolerance);
    
    EXPECT_NEAR(0, p.points()[4].x, tolerance);
    EXPECT_NEAR(1, p.points()[4].y, tolerance);
    
    EXPECT_NEAR(-1, p.points()[5].x, tolerance);
    EXPECT_NEAR(0, p.points()[5].y, tolerance);
}