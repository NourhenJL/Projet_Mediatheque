#ifndef LIVRE_H
#define LIVRE_H
#include"Doc.h"
#include <iostream>
using namespace std ;


class Livre : public Doc{

int nombrepage;
//int nbEmpruntsTotal=0;
static const int duree=6*7;
static const double tarif=0.5;
public :
Livre (string cod="", string title="" , string aut="", string year="", int nbrepage=0);
~Livre ()
{   }
int dureeEmprunt ();
double tarifEmprunt();

virtual string affiche();
virtual string affichefich();


int getnombrepage();

void setnombrepage(int nb);
};
#endif // LIVRE_H
