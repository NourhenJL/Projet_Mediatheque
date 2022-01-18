#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include"fichier.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Doc.h"
#include "FicheEmprunt.h"
#include "Genre.h"
#include "Audio.h"
#include "Video.h"
#include "Livre.h"
#include "Localisation.h"
#include "Client.h"

#include "CategorieClient.h"
#include "date.h"

using namespace std;
class Mediatheque
{
string nom ;
vector <Client>listeClient;
vector <CategorieClient>listeCategorie;
vector <FicheEmprunt>listeFiche;
vector <Doc*>listeDoc;
vector <Localisation>listeLoc;
vector <Genre>listeGenre;

public :
Mediatheque (string n="");

~Mediatheque ();
void ajouterCategorieClient ();
void modifierCategorieClient ();
void supprimerCategorieClient ();
void inscrireClient ();
void changerCategorieClient ();
void afficherCaracteristiquesClient (/*Client cl*/);
void modifierCaracteristiquesClient ();
void renouvelerInscriptionClient ();
void resilierClient ();
void changerAdresseClient ();
void consulterEmpruntsClient ();
void ajouterAudio ();
void ajouterLivre ();
void ajouterVideo ();
void rendreConsultableDocument ();
void rendreEmpruntableDocument ();
void retirerDocument ();
void emprunterDocument ();
void restituerDocument ();
void trouverEmpruntsEnRetard ();
void afficherStatistiques ();
void consulterCatalogueDocuments ();
void bloquerClient();
void debloquerClient();
Doc* chercherdoc();
Client chercherclient();

};
void EnTete();
void Color(int couleurDuTexte,int couleurDeFond);
#endif // MEDIATHEQUE_H


