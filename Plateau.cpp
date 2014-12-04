/* 
 * File:   Plateau.cpp
 * Author: eleve
 * 
 * Created on 1 décembre 2014, 15:45
 */

#include "Plateau.h"

Plateau::Plateau() {
}

Plateau::Plateau(const Plateau& orig) {
}

Plateau::~Plateau() {
}

void Plateau::affichage(){
    for (int i=1;i<=tableau.size();i++){
        for (int j=1;j<=tableau.size();j++){
            switch (tableau[i][j]) {
                case BLANC:
                    cout << "B";
                    break;
                case NOIR:
                    cout << "N";
                    break;
                case VIDE:
                    cout << "+";
            }
        }
        cout << endl;
    }
}

