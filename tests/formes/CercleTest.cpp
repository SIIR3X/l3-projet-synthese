#include "formes/Cercle.h"
#include <gtest/gtest.h>

TEST(Cercle, ConstructeurAvecValeurs) {
    // Arrange
    Vecteur2D centre(1, 2);
    double rayon = 3;

    // Act
    Cercle c(centre, rayon);

    // Assert
    EXPECT_EQ(centre, c.centre());
    EXPECT_EQ(rayon, c.rayon());
}

TEST(Cercle, Translation) {
    // Arrange
    Vecteur2D centre(1, 2);
    double rayon = 3;
    Cercle c(centre, rayon);

    // Act
    c.translation(Vecteur2D(1, 1));

    // Assert
    EXPECT_EQ(Vecteur2D(2, 3), c.centre());
}

TEST(Cercle, Homothetie) {
    // Arrange
    Vecteur2D centre(1, 2);
    double rayon = 3;
    Cercle c(centre, rayon);

    // Act
    c.homothetie(Vecteur2D(0, 0), 2);

    // Assert
    EXPECT_EQ(Vecteur2D(2, 4), c.centre());
    EXPECT_EQ(6, c.rayon());
}

TEST(Cercle, Rotation) {
    // Arrange
    Vecteur2D centre(1, 0);
    double rayon = 1;
    Cercle c(centre, rayon);
    const double tolerance = 1e-10;

    // Act
    c.rotation(Vecteur2D(0, 0), PI/2);

    // Assert
    EXPECT_NEAR(0, c.centre().x, tolerance);
    EXPECT_NEAR(1, c.centre().y, tolerance);
}

TEST(Cercle, Aire) {
    // Arrange
    Vecteur2D centre(0, 0);
    double rayon = 1;
    Cercle c(centre, rayon);
    const double tolerance = 1e-10;

    // Act
    double aire = c.aire();

    // Assert
    EXPECT_NEAR(PI, aire, tolerance);
}