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
    bool groupePris(Position pos, vector<Position> &outGroupe);
    virtual ~Plateau();
    void affichage(); 
    void initialisation();
    Position entreeClavier(Pierre joueur);
    void jouer();
    
private:

};

#endif	/* PLATEAU_H */

