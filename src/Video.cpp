#include "Video.h"

Video::Video (string cod, string title , string aut, string year,int dureevid,string mention):Doc(cod,title,aut,year)
{
       dureefilm=dureevid;
       mentionlegale=mention;
}
void Video::afficher_la_mention_legale()
{
 cout <<"la mention est :"<<mentionlegale <<endl;
}
int Video::dureeEmprunt ()
{
       return dureeEmp;
}
double Video::tarifEmprunt()
{
       return tarifEmp;
}

int Video::getdureefilm()
{return dureefilm;}

string Video::getmentionlegale()
{return mentionlegale;}


string Video::affiche()
{
stringstream aff;
string ch=Doc::affiche();
aff<<ch<<"La duree du film: "<<dureefilm<<"\nLa mention legale: "<<mentionlegale<<endl;
return aff.str();

}
string Video::affichefich()
{stringstream aff;
string ch=Doc::affichefich();
aff<<"Video "<<ch<<" "<<dureefilm<<" "<<mentionlegale;
return aff.str();
}
/*int Video::getnbEmpruntsTotal()
{return nbEmpruntsTotal;}*/

void Video::setdureefilm(int d)
{dureefilm=d;}

void Video::setmentionlegale(string m)
{mentionlegale=m;}

/*void Video::setnbEmpruntsTotal(int nb)
{nbEmpruntsTotal=nb;}

void Video::setdureeEmp(int d)
{dureeEmp=d;}

void Video::settarifEmp(double t)
{tarifEmp=t;}*/



