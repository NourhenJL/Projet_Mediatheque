#include "Audio.h"

Audio::Audio (string cod, string title , string aut, string year ,string classi):Doc(cod,title,aut,year)
{
       classification=classi;
      // setnbEmprunts(0);
}
int Audio::dureeEmprunt()
{
       return duree;
}
double Audio::tarifEmprunt()
{
       return tarif;
}
string Audio::affiche()
{stringstream aff;
string ch=Doc::affiche();
aff<<ch<<"Classification: "<<classification<<endl;
return aff.str();
}
string Audio::affichefich()
{stringstream aff;string ch=Doc::affichefich();

aff<<"Audio"<<" "<<ch<<" "<<classification;
return aff.str();
}

void  Audio::setclassification(string c) {classification=c;}
//void  Audio::setnbEmpruntsTotal(int nb){nbEmpruntsTotal=nb;}

string  Audio::getclassification() {return classification;}
//int  Audio::getnbEmpruntsTotal(){return nbEmpruntsTotal;}

