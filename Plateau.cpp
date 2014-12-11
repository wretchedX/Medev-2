/* 
 * File:   Plateau.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 15:45
 */

#include "Plateau.h"
//#include <algorithm>
//Algorithm ne marche pas...

bool contain ( vector<Position> v, Position e)
{
    for( int i = 0 ; i < v.size() ; i++)
    {
        if(v[i].x==e.x && v[i].y == e.y)
            return true;
    }
    return false;
}






Plateau::Plateau() {
}

Plateau::Plateau(const Plateau& orig) {
}

Plateau::~Plateau() {
}

void Plateau::jouer()
{
    Pierre joueurActuel = NOIR; 
    
    while(1)
    {
        Pierre joueurAutre = joueurActuel==NOIR?BLANC:NOIR;
        
        affichage();
        Position pos = entreeClavier(joueurActuel);
        
        bool suicide = true;
        
        if(pos.x >= 0 && pos.x < TAILLE_TABLEAU && pos.y >= 0 && pos.y < TAILLE_TABLEAU)
        {
            tableau[pos.x][pos.y] = joueurActuel;
            
            
            if(pos.x>0)
            {
                Position ouest = {pos.x-1 , pos.y};
                vector<Position> groupeOuest;
                bool gpOuest = groupePris(ouest, groupeOuest);
                if ((gpOuest == true)&&(tableau[pos.x-1][pos.y]==joueurAutre))
                {
                    capturer(groupeOuest);
                    suicide = false;
                }
                
            }
            if(pos.y>0)
            {
                Position nord = {pos.x , pos.y-1};
                vector<Position> groupeNord;
                bool gpNord = groupePris(nord, groupeNord);
                if ((gpNord == true)&&(tableau[pos.x][pos.y-1]==joueurAutre))
                {
                    capturer(groupeNord);
                    suicide = false;
                }
            }
            if(pos.x<TAILLE_TABLEAU-1)
            {
                Position est = {pos.x+1 , pos.y};
                vector<Position> groupeEst;
                bool gpEst = groupePris(est, groupeEst);
                if ((gpEst == true)&&(tableau[pos.x+1][pos.y]==joueurAutre))
                {
                    capturer(groupeEst);
                    suicide = false;
                }
            }
            if(pos.y<TAILLE_TABLEAU-1)
            {
                Position sud = {pos.x , pos.y+1};
                vector<Position> groupeSud;
                bool gpSud = groupePris(sud, groupeSud);
                if ((gpSud == true)&&(tableau[pos.x][pos.y+1]==joueurAutre))
                {
                    capturer(groupeSud);
                    suicide = false;
                }
            }
            if(suicide)
            {
                if(groupePris(pos,*(new vector<Position>)))
                {
                    tableau[pos.x][pos.y] = VIDE;
                    //Le joueur rejoue.
                }
                else
                {
                    joueurActuel = joueurActuel==NOIR?BLANC:NOIR;
                    // On change de joueur
                }                
                
            }
            else
            {
                //changement de joueur
                joueurActuel = joueurActuel==NOIR?BLANC:NOIR;
            }
        }
        
        
        
    }
}

Position Plateau::entreeClavier(Pierre joueur)
{
    int ligne = -1;
    int colonne = -1;
    Position choix;
    cout << "Joueur " << (joueur==NOIR?"Noir":"Blanc") << ", entrez numero de ligne (pour passer entrer un nombre negatif)" << endl;
    cin >> ligne;
    cout << endl << "Entrez numero de colonne" << endl;
    cin >> colonne;
    if(ligne >= 0 && ligne < TAILLE_TABLEAU && colonne >= 0 && colonne < TAILLE_TABLEAU){
        if (tableau[ligne][colonne] == VIDE)
        {
            choix.x = ligne;
            choix.y = colonne;
        }
    }
    return choix;
}


void Plateau::capturer(vector<Position> groupe)
{
    Pierre couleur;
    int points = groupe.size();
    for (int i = 0 ; i < groupe.size() ; i++)
    {
        couleur = tableau[groupe[i].x][groupe[i].y];
        tableau[groupe[i].x][groupe[i].y] = VIDE;
    }
    if (couleur == NOIR)
    {
        captureBlanc+=points;
    }
    if (couleur == BLANC)
    {
        captureNoir+=points;
    }
}

bool Plateau::groupePris(Position pos, vector<Position> &outGroupe)
{
    if(tableau[pos.x][pos.y] == VIDE) return true;
    
    outGroupe.push_back(pos);
    bool pris = true;
    
    vector<Position> nexts;
    nexts.push_back({1,0});
    nexts.push_back({-1,0});
    nexts.push_back({0,1});
    nexts.push_back({0,-1});
    
    for(int i = 0 ; i < nexts.size() ; i ++)
    {
        Position next = {pos.x + nexts[i].x , pos.y + nexts[i].y};
        
        if (next.x >= 0 && next.x < TAILLE_TABLEAU && next.y >= 0 && next.y < TAILLE_TABLEAU)
        {
            if (tableau[next.x][next.y] == VIDE) pris = false;
            else {
                bool estDejaDansGroupe = contain (outGroupe,next);
                if (tableau[next.x][next.y] == tableau[pos.x][pos.y] && !estDejaDansGroupe) {
                     pris = pris && groupePris(next, outGroupe);
                }
            }
        }
    }
    return pris;
}

void Plateau::affichage() {
    system("cls");
    
    cout << "    \t";
    for (int i = 0 ; i < tableau.size() ; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < tableau.size(); i++) {
        cout << i << " : \t";
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
