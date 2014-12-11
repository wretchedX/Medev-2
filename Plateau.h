/* 
 * File:   Plateau.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 15:45
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#define TAILLE_TABLEAU 9

#include <vector>
#include "Structures.h"


using namespace std;
class Plateau {
public:
    Plateau();
    Plateau(const Plateau& orig);
    vector <vector <Pierre> > tableau;
    vector <vector <vector <Pierre> > > tableauxPrecedents;
    bool groupePris(Position pos, vector<Position> &outGroupe); // outgroupe = le groupe qui contient la pierre considérée (rempli par la fonction)
    virtual ~Plateau();
    void affichage(); 
    void initialisation();
    Position entreeClavier(Pierre joueur);
    void jouer();
    void capturer(vector<Position> groupe);
    bool ko();
//private 
    int captureBlanc;
    int captureNoir;
private:
    
};

bool contain ( vector<Position> v, Position e);
bool contain (vector <vector <vector <Pierre> > > v, vector< vector<Pierre> > e);
#endif	/* PLATEAU_H */

