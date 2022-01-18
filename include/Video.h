#ifndef VIDEO_H
#define VIDEO_H

#include "Doc.h"
#include <iostream>
#include <string.h>
using namespace std ;


class Video :public Doc
{
int dureefilm;
string mentionlegale;
//int nbEmpruntsTotal=0;
static const int dureeEmp=2*7;
static const double tarifEmp=1.5;
public :
Video (string cod="", string title="" , string aut="", string year="",int dureevid=0,string mention="");
~Video ()
{   }
void afficher_la_mention_legale ();
int dureeEmprunt ();
double tarifEmprunt();

int getdureefilm();
string getmentionlegale();
//int getnbEmpruntsTotal();

virtual string affiche();
virtual string affichefich();


void setdureefilm(int d);
void setmentionlegale(string m);
//void setnbEmpruntsTotal(int nb);
//void setdureeEmp(int d);
//void settarifEmp(double t);

};

#endif // VIDEO_H
