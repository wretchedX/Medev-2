#include <gtest/gtest.h>
#include "Plateau.h"

TEST(plateau_initialisation_test, zero) {
    Plateau p;
    p.initialisation();
    for (int i = 0; i < p.tableau.size(); i++)
    {
        for (int j = 0; j < p.tableau.size(); j++)
            EXPECT_EQ(VIDE,p.tableau[i][j]);
    }
}

TEST(plateau_groupePris_test, prisDansUnCoin) {
    Plateau p;
    p.initialisation();
    p.tableau[0][0] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[0][1] = NOIR;
    Position pos = {0,0};
    vector <Position> vec;
    EXPECT_EQ(true, p.groupePris( pos, vec ));
}

TEST(plateau_groupePris_test, prisAuMilieu) {
    Plateau p;
    p.initialisation();
    p.tableau[1][1] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[0][1] = NOIR;   
    p.tableau[1][2] = NOIR;
    p.tableau[2][1] = NOIR;
    Position pos = {1,1};
    vector <Position> vec;
    EXPECT_EQ(true, p.groupePris( pos, vec ));
    //EXPECT_EQ(pos.x , vec[0].x);
    //EXPECT_EQ(pos.y , vec[0].y);
}
