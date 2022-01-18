#ifndef DOC_H
#define DOC_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>


#include "Localisation.h"
#include"Genre.h"

using namespace std ;


class Doc // classe abstraite
{
protected :
string code ;
string titre ;
string auteur;
string annee;
int nbEmprunts;
bool empruntable;
bool emprunte;
Genre g;
Localisation l;

public :
Doc (string cod="", string title ="", string aut="", string year ="");
~Doc ()
{  }
Localisation localiser(Doc*d);
virtual int dureeEmprunt ()=0;
virtual double tarifEmprunt()=0;
/*virtual void setnombrepage(int nb);
virtual void setdureefilm(int d);
virtual void setmentionlegale(string m);
virtual void setclassification(string c) ;*/
//void setnbEmpruntsTotal(int nb);


// methodes emprunter , restitier , bool rendre empruntable (document )

bool operator==(Doc*d);
virtual string affiche();
virtual string affichefich();
string getcode() ;
string gettitre() ;
string getauteur();
string getannee();
int getnbEmprunts();
bool getempruntable();
bool getemprunte();
Genre getgenre();
Localisation getloc();

void setcode(string c) ;
void settitre(string t) ;
void setauteur(string a);
void setannee(string an);
void setnbEmprunts(int nb);
void setempruntable(bool emp);
void setemprunte(bool emp);
void setgenre(Genre g);
void setloc(Localisation l);
};

#endif // DOC_H
