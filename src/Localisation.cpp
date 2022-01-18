#include "Localisation.h"

Localisation::Localisation(string sa,string ray)
{
salle=sa;
rayon=ray;
}
bool  Localisation::operator==(Localisation loc)
{
    return salle==loc.salle && rayon==loc.rayon;
}
string Localisation:: get_salle(){return salle ;}
string Localisation:: get_rayon() { return rayon ;}
string Localisation::affiche()
{stringstream ch;
    ch<<"\nLe document se trouve dans:   -La salle: "<<salle<<"\t\t-Le rayon: "<<rayon;
    return ch.str();
}

string Localisation::affichefich()
{stringstream ch;
    ch<<"Localisation "<<salle<<" "<<rayon;
    return ch.str();
}
// **** set *****
void Localisation:: set_salle(string sal) { salle=sal ; }
void Localisation:: set_rayon(string ray) {rayon=ray  ; }
