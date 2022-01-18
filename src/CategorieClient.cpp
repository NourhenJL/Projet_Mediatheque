#include "CategorieClient.h"

CategorieClient::CategorieClient(string nom,int nbEmpruntsMaxi,double cot ,double coefT ,double coefd , bool codeRedactif  )
{
       nomCat=nom;
       nbEmpruntsMax=nbEmpruntsMaxi;
       cotisation=cot;
       coefTarif=coefT;
       coefduree=coefd;
       codedReductionactif=codeRedactif;
}

string CategorieClient :: get_nomCat() {return nomCat ;}
int CategorieClient :: get_nbEmpruntsMax() {return nbEmpruntsMax ; }
double CategorieClient :: get_cotisation() {return cotisation ; }
double CategorieClient :: get_coefTarif() {return coefTarif ; }
double CategorieClient :: get_coefduree() {return coefduree ; }
bool CategorieClient :: get_codedReductionactif() {return codedReductionactif ; }

// ******** ****** SET ***************
void CategorieClient :: set_nomCat(string n) { nomCat=n ; }
void CategorieClient :: set_nbEmpruntsMax(double nbE) {nbEmpruntsMax=nbE ;}
void CategorieClient :: set_cotisation(double cot) {cotisation=cot;}
void CategorieClient :: set_coefTarif(double coef_tarif) {coefTarif=coef_tarif; }
void CategorieClient :: set_coefduree(double coef_duree) {coefduree=coef_duree;}
void CategorieClient :: set_codedReductionactif(bool codeRed) {codedReductionactif=codeRed ;}

string CategorieClient::affiche()
{stringstream aff;
string ch;
if (codedReductionactif==true)
    aff<<"Nom de la cat"<<char (130)<<"gorie: "<<nomCat<<"\nNombre d'emprunts maximal:  "<<nbEmpruntsMax<<"\nCotisation:  "<<cotisation<<"\nCoefficient tarif:  "<<coefTarif<<"\nCoefficient de dur"<<char (130)<<"e: "<<coefduree<<"\nLe code de reduction est activ"<<char (130)<<endl;
else
    aff<<"Nom de la cat"<<char (130)<<"gorie: "<<nomCat<<"\nNombre d'emprunts maximal:  "<<nbEmpruntsMax<<"\nCotisation:  "<<cotisation<<"\nCoefficient tarif:  "<<coefTarif<<"\nCoefficient de dur"<<char (130)<<"e: "<<coefduree<<"\nLe code de reduction n'est pas activ"<<char(130)<<endl;



return aff.str();
}

string CategorieClient::affichefich()
{stringstream aff;
string ch;
    aff<<"Categorie "<<nomCat<<" "<<nbEmpruntsMax<<" "<<cotisation<<" "<<coefTarif<<" "<<coefduree<<" "<<codedReductionactif;
return aff.str();
}

