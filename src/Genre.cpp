#include "Genre.h"

Genre::Genre (string name )
{
     nom=name;
     set_nbEmprunts(0);
}

bool Genre::operator==(Genre g)
{
    return nom==g.nom;
}

bool Genre::operator<(Genre&g)
{
    return nbEmprunts<g.nbEmprunts;
}

    // **** get ****

string Genre::get_nom() { return nom ;}
int Genre::get_nbEmprunts() { return nbEmprunts ;}

 string Genre::affiche()
 {stringstream ch;
     ch<<"\nGenre: "<<nom;
     return ch.str();
 }


  string Genre::affichefich()
 {stringstream ch;
     ch<<"Genre "<<nom<<" "<<nbEmprunts;
     return ch.str();
 }
// ***** set ****
void Genre::set_nom(string n) { nom=n ;}
void Genre::set_nbEmprunts(int nbE) { nbEmprunts=nbE ;}
