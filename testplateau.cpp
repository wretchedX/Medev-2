#include <gtest/gtest.h>
#include "Plateau.h"

TEST(plateau_initialisation_test, zero) {
    Plateau p;
    p.initialisation();
    EXPECT_EQ(VIDE,p.tableau[0][0]);
}

