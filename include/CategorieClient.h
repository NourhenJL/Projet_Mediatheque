#ifndef CATEGORIECLIENT_H
#define CATEGORIECLIENT_H
#include<sstream>
#include <iostream>
#include <string.h>
    using namespace std ;

class CategorieClient
{
 string nomCat ;
int nbEmpruntsMax ;
double cotisation ;
double coefTarif ;
double coefduree ;
bool codedReductionactif ;
public :
CategorieClient (string nom ="" ,int nbEmpruntsMaxi = 0 ,double coti=0.0 ,double coefT =0.0,double coefd=0.0 , bool codedRedactif =false );
//*************** get *****************
string get_nomCat() ;
int get_nbEmpruntsMax() ;
double get_cotisation() ;
double get_coefTarif() ;
double get_coefduree() ;
bool get_codedReductionactif() ;
//********************** set *********
void set_nomCat(string n) ;
void set_nbEmpruntsMax(double nbE) ;
void set_cotisation(double cot) ;
void set_coefTarif(double coef_tarif) ;
void set_coefduree(double coef_duree) ;
void set_codedReductionactif(bool codeRed) ;

string affiche();
string affichefich();

~CategorieClient()
{   }
};

#endif // CATEGORIECLIENT_H
