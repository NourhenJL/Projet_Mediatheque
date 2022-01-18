#include "Doc.h"

#include "Genre.h"
#include"Localisation.h"
Doc::Doc (string cod, string title , string aut, string year )
{
       code=cod;
       titre=title;
       auteur=aut;
       annee=year;
       setnbEmprunts(0);setempruntable(false);setemprunte(false);
}
bool Doc::operator==(Doc*d)
{
    return code==d->code;
}
string Doc::affiche()
{stringstream aff;
string ch;
if(emprunte) ch="emprunte"; else ch="disponible";
    if (empruntable)

    aff<<"********************* DOCUMENT *********************\n"<<"Code: "<<code<<"\nTitre: "<<titre<<"\nAuteur: "<<auteur<<"\nAnn"<<char (130)<<"e de publication: "<<annee<<"\nNombre d'emprunts: "<<nbEmprunts<<"\nStatut: empruntable "<<"\nEtat: "<<ch<<g.affiche()<<l.affiche()<<endl;
else aff<<"********************* DOCUMENT *********************\n"<<"Code: "<<code<<"\nTitre: "<<titre<<"\nAuteur: "<<auteur<<"\nAnn"<<char (130)<<"e de publication: "<<annee<<"\nNombre d'emprunts: "<<nbEmprunts<<"\nStatut: consultable"<<"\nEtat: "<<ch<<g.affiche()<<l.affiche()<<endl;
return aff.str();
}
string Doc::affichefich()
{stringstream aff;


aff<<code<<" "<<titre<<" "<<auteur<<" "<<annee<<" "<<nbEmprunts<<" "<<empruntable<<" "<<emprunte<<" "<<l.get_salle()<<" "<<l.get_rayon()<<" "<<g.get_nom()<<" "<<g.get_nbEmprunts();

return aff.str();
}

string Doc::getcode() {return code;}
string Doc::gettitre() {return titre;}
string Doc::getauteur(){return auteur;}
string Doc::getannee(){return annee;}
int Doc::getnbEmprunts(){return nbEmprunts; }
bool Doc::getempruntable(){return empruntable;}
bool Doc::getemprunte(){return emprunte;}
Genre Doc::getgenre(){return g;}
Localisation Doc::getloc(){return l;}

void Doc::setcode(string c) {code=c;}
void Doc::settitre(string t) {titre=t;}
void Doc::setauteur(string a){auteur=a;}
void Doc::setannee(string an){annee=an;}
void Doc::setnbEmprunts(int nb){nbEmprunts=nb;}
void Doc::setempruntable(bool emp){empruntable=emp;}
void Doc::setemprunte(bool emp){emprunte=emp;}
void Doc::setgenre(Genre genre){g=genre;}
void Doc::setloc(Localisation loc){l=loc;}
