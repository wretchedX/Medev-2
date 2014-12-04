/* 
 * File:   Plateau.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 15:45
 */

#include "Plateau.h"
#include <algorithm>
Plateau::Plateau() {
}

Plateau::Plateau(const Plateau& orig) {
}

Plateau::~Plateau() {
}



bool Plateau::groupePris(Position pos, vector<Position> &outGroupe)
{
    outGroupe.push_back(pos);
    bool pris = true;
    
    for(int i = -1 ; i < 2 ; i++++)
    {
        for (int j = -1 ; j < 2 ; j++++)
        {
            Position next = {pos.x + i , pos.y + j};
            bool estDejaDansGroupe = find(outGroupe.begin(),outGroupe.end(), next)!= outGroupe.end();
            
            if (next.x >= 0 && next.x < TAILLE_TABLEAU && next.y >= 0 && next.y < TAILLE_TABLEAU)
            {
                if (tableau[next.x][next.y] == Pierre.VIDE) pris = false;
                else if (tableau[next.x][next.y] == tableau[pos.x][pos.y] && !estDejaDansGroupe)
                     pris = pris && groupePris(next, outGroupe);
            }
        }
    }
    return pris;
}