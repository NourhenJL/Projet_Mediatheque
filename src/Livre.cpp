#include "Livre.h"

Livre::Livre (string cod, string title , string aut, string year, int nbrepage):Doc(cod,title,aut,year)
{
       nombrepage=nbrepage;
}
int Livre::dureeEmprunt ()
{
   return  duree;
}
double Livre::tarifEmprunt ()
{
    return tarif ;
}

string  Livre::affiche()
{stringstream aff;
string ch=Doc::affiche();
aff<<"Livre\n"<<ch<<"Nombre de page: "<<nombrepage<<endl;
return aff.str();
}
string Livre::affichefich()
{stringstream aff;
string ch=Doc::affichefich();
aff<<"Livre "<<ch<<" "<<nombrepage;
return aff.str();
}

int Livre::getnombrepage(){return nombrepage;}

void Livre::setnombrepage(int nb){nombrepage=nb;}
