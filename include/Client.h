#ifndef CLIENT_H
#define CLIENT_H

#include <string.h>
#include<vector>
#include"date.h"
#include "CategorieClient.h"
#include"FicheEmprunt.h"
using namespace  std ;
class FicheEmprunt;

class Client
{
string nom ;
string prenom ;
string adresse ;
date dateinsc ;
date daterenouv;
int nbEmpruntsEffectues;
int nbEmpruntsDepasses;
int nbEmpruntsEncours;
int codeReduction ;
bool enRetard;
CategorieClient categ;
vector <FicheEmprunt> fiches;
public :
Client (string name="",string pren="",string adr="",int nbEmpruntsEff=0,int nbEmpruntsDep=0,int nbEmpruntsEnc=0,int codeR=0,bool Retard=false);
~Client ()
{  }
bool operator==(Client c);
string getnom();
string getprenom();
string getadresse();
date getdateinsc();
date getdaterenouv();
int getnbEmpruntsEffectues();
int getnbEmpruntsDepasses();
int getnbEmpruntsEncours();
int getcodeReduction();
bool getenRetard();
CategorieClient getcategorie();
vector <FicheEmprunt> getfiches();

void ajouterfiche(FicheEmprunt fe);
void setnom(string n);
void setprenom(string p);
void setadresse(string a);
void setdateinsc(date d);
void setdaterenouv(date d);
void setnbEmpruntsEffectues(int nb);
void setnbEmpruntsDepasses(int nb);
void setnbEmpruntsEncours(int nb);
void incnbEmpruntsEffectues();
void incnbEmpruntsDepasses();
void incnbEmpruntsEncours();
void decnbEmpruntsEffectues();
void decnbEmpruntsDepasses();
void decnbEmpruntsEncours();
void setcodeReduction(int c);
void setenRetard(bool b);
void setcategorie(CategorieClient c);
string affichefich();
string affiche();

void changer_une_adresse (Client cli);
};

#endif // CLIENT_H
