#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include "Doc.h"
#include <string.h>

using namespace std ;
class Audio :public Doc
{
string classification ;
//int nbEmpruntsTotal ;
static const int duree=4*7;
static const double tarif=1.0 ;
public:
Audio (string cod="", string title ="", string aut="", string year ="",string classi="") ;
virtual ~Audio ()
{  }
int dureeEmprunt ();
double tarifEmprunt();

virtual string affiche();
virtual string affichefich();

void setclassification(string c) ;
//void setnbEmpruntsTotal(int nb);

string getclassification() ;
//int getnbEmpruntsTotal();

};

//***********


#endif // AUDIO_H
