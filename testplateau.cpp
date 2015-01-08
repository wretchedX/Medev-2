/* 
 * Rédigé par
 * Maximilien Bellot
 * Carl-Alexandre Michau
 * Nicolas Muller
 * 
 */

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
    p.tableau[0][1] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[1][1] = NOIR;
    p.tableau[0][2] = NOIR;
    Position pos = {0,0};
    vector <Position> vec;
    EXPECT_EQ(true, p.groupePris( pos, vec ));
}

TEST(plateau_groupePris_test, prisAuMilieu) { 
    Plateau p;
    p.initialisation();
    p.tableau[1][1] = BLANC;
    p.tableau[1][2] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[0][1] = NOIR;
    p.tableau[0][2] = NOIR;
    p.tableau[1][3] = NOIR;
    p.tableau[2][1] = NOIR;
    p.tableau[2][2] = NOIR;
    Position pos = {1,1};
    Position pos2 = {1,2};
    vector <Position> vec;
    bool pris = p.groupePris(pos, vec );
    EXPECT_EQ(true, pris);
    EXPECT_EQ(pos2.x , vec[1].x);
    EXPECT_EQ(pos2.y , vec[1].y);
}

TEST(plateau_groupePris_test, pasPris)
{
    Plateau p;
    p.initialisation();
    p.tableau[1][1] = BLANC;
    p.tableau[1][2] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[0][1] = NOIR;
    p.tableau[0][2] = NOIR;
    p.tableau[1][3] = NOIR;
    p.tableau[2][1] = NOIR;
    Position pos = {1,1};
    vector <Position> vec;
    EXPECT_EQ(false, p.groupePris( pos, vec ) );
}

TEST (contain_test , contientUnePosition)
{
    vector <Position> vec;
    Position pos = {1,1};
    vec.push_back(pos);
    EXPECT_EQ(true , contain( vec, pos ) );
}

TEST (plateau_capturer_test, testDeCapture)
{
    Plateau p;
    p.initialisation();
    p.tableau[1][1] = BLANC;
    p.tableau[1][2] = BLANC;
    p.tableau[1][0] = NOIR;
    p.tableau[0][1] = NOIR;
    p.tableau[0][2] = NOIR;
    p.tableau[1][3] = NOIR;
    p.tableau[2][1] = NOIR;
    p.tableau[3][3] = BLANC;
    vector <Position> groupe;
    groupe.push_back({1,1});
    groupe.push_back({1,2});
    p.capturer(groupe);
    EXPECT_EQ(VIDE, p.tableau[1][1]);
    EXPECT_EQ (VIDE, p.tableau[1][2]);
    EXPECT_EQ(BLANC, p.tableau[3][3]);
    EXPECT_EQ(NOIR, p.tableau[1][0]);
}

TEST (kotest, ko)
{
    Plateau p1; 
    p1.initialisation(); 
    p1.tableau[1][1] = BLANC;
    Plateau p2; 
    p2.initialisation(); 
    p2.tableau[2][2] = NOIR;
    Plateau p3; 
    p3.initialisation(); 
    p3.tableau[3][4] = BLANC;
    Plateau p4; 
    p4.initialisation(); 
    p4.tableau[1][1] = BLANC; 
    p4.tableau[5][0] = BLANC;
    p4.tableau[8][7] = NOIR;
    
    vector < vector < vector < Pierre > > > liste;
    liste.push_back(p1.tableau);
    liste.push_back(p2.tableau);
    liste.push_back(p3.tableau);
    liste.push_back(p4.tableau);
    
    
    Plateau ptest; 
    ptest.initialisation(); 
    ptest.tableau[1][1] = BLANC;
    
    Plateau ptest2; 
    ptest2.initialisation(); 
    ptest2.tableau[3][4] = NOIR;
    
    EXPECT_EQ(true, contain(liste, ptest.tableau));
    EXPECT_EQ(false, contain(liste, ptest2.tableau)); 
     
}