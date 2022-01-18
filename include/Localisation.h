#ifndef LOCALISATION_H
#define LOCALISATION_H


#include <iostream>
#include <string.h>
#include<sstream>
using namespace std ;


class Localisation
{
string salle;
string rayon ;

public :
Localisation(string sa="",string ray="");
~Localisation ()
{    }
bool  operator==(Localisation loc);
string affiche();
string affichefich();

// **** get ****
string get_salle();
string get_rayon() ;

// **** set *****
void set_salle(string sal);
void set_rayon(string ray) ;

};

#endif // LOCALISATION_H
