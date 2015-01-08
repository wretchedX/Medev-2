/* 
 * File:   Plateau.h
 * 
 * Rédigé par
 * Maximilien Bellot
 * Carl-Alexandre Michau
 * Nicolas Muller
 * 
 * Created on 1 décembre 2014, 15:45
 * 
 * Classe gérant le plateau de jeu qui implémente par ses méthodes les règles du jeu de go
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#define TAILLE_TABLEAU 9

#include <vector>
#include "Structures.h"


using namespace std;

/*!
 * @class Plateau
 * @brief La classe Plateau
 * 
 * Cette classe gère le plateau de jeu et l'affichage et diverses autres choses
 */
class Plateau {
public:
    Plateau();
    Plateau(const Plateau& orig);
    vector <vector <Pierre> > tableau; // plateau
    vector <vector <vector <Pierre> > > tableauxPrecedents; // plateaux précédents
    bool groupePris(Position pos, vector<Position> &outGroupe); // outgroupe = le groupe qui contient la pierre considérée (rempli par la fonction)
    virtual ~Plateau();
    void affichage(); 
    void initialisation();
    Position entreeClavier(Pierre joueur);  // récupère au clavier la position souhaitée
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

