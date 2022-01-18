#include "Client.h"

Client::Client (string name,string pren,string adr,int nbEmpruntsEff,int nbEmpruntsDep,int nbEmpruntsEnc,int codeR,bool Retard)
{
nom =name;
prenom=pren;
adresse=adr;

nbEmpruntsEffectues=nbEmpruntsEff;
nbEmpruntsDepasses=nbEmpruntsDep;
nbEmpruntsEncours=nbEmpruntsEnc;
codeReduction=codeR;
enRetard=Retard;
CategorieClient c("X");
setcategorie(c);
}
void Client::changer_une_adresse (Client cli)
{
       cout <<"Entrer la nouvelle adresse"<<endl;
       cin >>cli.adresse;
}
bool Client::operator==(Client c)
{
    return c.nom==nom && c.adresse==adresse && c.prenom==prenom;
}

string Client::getnom(){return nom;}
string Client::getprenom(){return prenom;}
string Client::getadresse(){return adresse;}
date Client::getdateinsc(){return dateinsc;}
date Client::getdaterenouv(){return daterenouv;}
int Client::getnbEmpruntsEffectues(){return nbEmpruntsEffectues;}
int Client::getnbEmpruntsDepasses(){return nbEmpruntsDepasses;  }
int Client::getnbEmpruntsEncours(){return nbEmpruntsEncours;}
int Client::getcodeReduction(){return codeReduction; }
bool Client::getenRetard(){return enRetard;}
CategorieClient Client::getcategorie(){return categ;}
vector <FicheEmprunt> Client::getfiches(){return fiches;}


void Client::ajouterfiche(FicheEmprunt fe)
{
    fiches.push_back(fe);
}

void Client::setnom(string n){nom=n;}
void Client::setprenom(string p){prenom=p;}
void Client::setadresse(string a){adresse=a;}
void Client::setdateinsc(date d){dateinsc=d;}
void Client::setdaterenouv(date d){daterenouv=d;}
void Client::incnbEmpruntsEffectues(){nbEmpruntsEffectues+=1;}
void Client::incnbEmpruntsDepasses(){nbEmpruntsDepasses+=1;}
void Client::incnbEmpruntsEncours(){nbEmpruntsEncours+=1;}
void Client::setnbEmpruntsEffectues(int nb){nbEmpruntsEffectues=nb;}
void Client::setnbEmpruntsDepasses(int nb){nbEmpruntsDepasses=nb;}
void Client::setnbEmpruntsEncours(int nb){nbEmpruntsEncours=nb;}
void Client::decnbEmpruntsEffectues(){nbEmpruntsEffectues-=1;}
void Client::decnbEmpruntsDepasses(){nbEmpruntsDepasses-=1;}
void Client::decnbEmpruntsEncours(){nbEmpruntsEncours-=1;}
void Client::setcodeReduction(int c){codeReduction=c;}
void Client::setenRetard(bool b){enRetard=b;}
void Client::setcategorie(CategorieClient c){categ=c;}


string Client::affichefich()
{stringstream aff;


    aff<<"Client "<<nom<<" "<<prenom<<" "<<adresse<<" "<<dateinsc<<" "<<daterenouv<<" "<<nbEmpruntsEffectues<<" "<<nbEmpruntsDepasses<<" "<<nbEmpruntsEncours<<" "<<codeReduction<<" "<<enRetard<< " "
    <<categ.get_nomCat()<<" "<<categ.get_nbEmpruntsMax()<<" "<<categ.get_cotisation()<<" "<<categ.get_coefTarif()<<
    " "<<categ.get_coefduree()<<" "<<categ.get_codedReductionactif();

return aff.str();
}

string Client::affiche()
{stringstream aff;
string ch;
if (enRetard==true)
    aff<<"********************* CLIENT *********************\n"<<"Nom: "<<nom<<"\nPr"<<char (130)<<"nom:  "<<prenom<<"\nAdresse:  "<<adresse<<"\nDate d incription: "<<dateinsc<<"\nDate de renouvellement: "<<daterenouv<<"\nNombre d'empreunts effectues:  "<<nbEmpruntsEffectues<<"\nNombre d'emprunts depass"<<char (130)<<"s: "<<nbEmpruntsDepasses<<"\nCode reduction:  "<<codeReduction<<"\nLe client est en retard"<<endl;
else
    aff<<"********************* CLIENT *********************\n"<<"Nom: "<<nom<<"\nPr"<<char (130)<<"nom:  "<<prenom<<"\nAdresse:  "<<adresse<<"\nDate d incription: "<<dateinsc<<"\nDate de renouvellement: "<<daterenouv<<"\nNombre d'empreunts effectues:  "<<nbEmpruntsEffectues<<"\nNombre d'emprunts depass"<<char (130)<<"s: "<<nbEmpruntsDepasses<<"\nCode reduction:  "<<codeReduction<<"\nLe client n est pas en retard"<<endl;

return aff.str();
}
