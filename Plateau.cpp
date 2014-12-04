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

void Plateau::jouer()
{
    Pierre joueurActuel = Pierre.NOIR; 
    
    while(1)
    {
        affichage();
        entreeClavier(joueurActuel);
        
        
        
    }
}

Position Plateau::entreeClavier(Pierre joueur)
{
    int ligne = -1;
    int colonne = -1;
    Position choix;
    cout << "Joueur" << joueur << ", entrez numero de ligne (pour passer entrer un nombre negatif)" << endl;
    cin >> ligne;
    cout << endl << "Entrez numero de colonne" << endl;
    cin >> colonne;
    if (tableau[ligne][colonne] == VIDE)
    {
        choix.x = ligne;
        choix.y = colonne;
    }
    return choix;
}


bool Plateau::groupePris(Position pos, vector<Position> &outGroupe)
{
    outGroupe.push_back(pos);
    bool pris = true;
    
    for(int i = -1 ; i < 2 ; i += 2)
    {
        for (int j = -1 ; j < 2 ; j+= 2)
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

void Plateau::affichage() {
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau.size(); j++) {
            switch (tableau[i][j]) {
                case BLANC: 
                    cout << "B ";
                    break;
                case NOIR:
                    cout << "N ";
                    break;
                case VIDE:
                    cout << "+ ";
            }
        }
        cout << endl;
    }
}

void Plateau::initialisation() {
    for (int i = 0; i < TAILLE_TABLEAU; i++) {
        vector < Pierre > colonne;
        for (int j = 0; j < TAILLE_TABLEAU; j++)
            colonne.push_back(VIDE);
        tableau.push_back(colonne);
    }
}
