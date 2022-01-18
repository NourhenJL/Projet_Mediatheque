#ifndef FICHEEMPRUNT_H
#define FICHEEMPRUNT_H

#include <time.h>
#include "Doc.h"

#include"date.h"
using namespace std ;

class Client;
class FicheEmprunt
{
date dateEmprunt ;
date dateLimite ;
date dateRappel  ;
bool depassee;
double tarif ;
Client*cli;
Doc*docu ;
public :
FicheEmprunt (bool depasse =false, double tar=0.0 );
~FicheEmprunt()
{  }
void calculer_le_tarif ();
int verifier_les_emprunts ();

// ******* get *************

date get_dateEmprunt() ;
date get_dateLimite() ;
date get_dateRappel()  ;
bool get_depassee();
double get_tarif() ;
Client* get_cli() ;
Doc* get_docu() ;

// ***** set *****
void set_dateEmprunt() ;
void set_dateLimite() ;
void set_dateRappel()  ;
void setdateEmprunt(date d);
void setdateLimite(date d);
void setdateRappel(date d);
void set_depassee(bool b );
void set_tarif(double trf) ;
void set_cli(Client*cl) ;
void set_docu (Doc*d);

string affichefich() ;
string affiche ();




};

#endif // FICHEEMPRUNT_H
