/* 
 * File:   Plateau.h
 * Author: eleve
 *
 * Created on 1 décembre 2014, 15:45
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#include <vector>

class Plateau {
public:
    Plateau();
    Plateau(const Plateau& orig);
    vector <vector <Pierre>> tableau;
    vector <vector <vector <Pierre>>> tableauxPrecedents;
    virtual ~Plateau();
private:

};

#endif	/* PLATEAU_H */
