#include "Mediatheque.h"
#include <algorithm>
#include <numeric>
#include "Mediatheque.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include "Client.h"
#include "date.h"

//***************** Fonction qui affiche l'entete *****************
void EnTete()
{
    system("cls");
    system("color F0");
    char tmp[128],dte[128];
    _strdate(dte);_strtime(tmp);
cout <<"\xc9";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" ;
cout <<"\xbb";
cout <<"\n\xba"<<dte<<"  \xba                  \xba  Mediatheque     \xba                 \xba"<<tmp<<"  \xba\n";
cout <<"\xc8";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd";
cout <<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
cout <<"\xbc";
cout <<"\n\n";
}

//***************** Fonction qui change la couleur *****************
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
       HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

Mediatheque::Mediatheque(string n)
{

       nom =n;
 //ctor
}

Mediatheque::~Mediatheque()
{
    //dtor
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::trouverEmpruntsEnRetard ()
{int choice;
    do{EnTete();lirefiche(listeFiche,"Fiches.txt");
    int l=listeFiche.size();
cout<<"Les emprunts en retard sont:"<<endl;
    for(int i=0;i<l;++i)
    {if (listeFiche[i].verifier_les_emprunts()==0)
         cout<<listeFiche[i].affiche();
    }
    cout<<             "Voulez vous sortir:"<<endl;
cout<<"                    0-Non          1-Oui"<<endl;
cout<<"                          choix: ";cin>>choice;
}while(choice==0);


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::rendreConsultableDocument ()
{int choice;
do{ liredocument(listeDoc,"Documents.txt");system("cls");
EnTete();
string code;
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;

bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==code)
            {
                test=true;
                listeDoc[i]->setempruntable(false);

                 Color(10,15);cout<<"L'op"<<char (130)<<"ration est effectu"<<char (130)<<"e avec succ"<<char (130)<<"s"<<endl;Color(0,15);

            }
        }
         enregistrerdoc(listeDoc,"Documents.txt");
        if(!test)
           {Color(12,15);cout <<"Le document n'existe pas"<<endl;Color(0,15);}

cout<<               "Voulez vous faire une autre op"<<char (130)<<"ration:"<<endl;
cout<<"                  0-Non                  1-Oui"<<endl;
cout<<"                              Choix: ";cin>>choice;
}while(choice==1);

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::rendreEmpruntableDocument ()
{
int choice;
do{ liredocument(listeDoc,"Documents.txt");system("cls");
EnTete();
string code;
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;


bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==code)
            {
                test=true;
                listeDoc[i]->setempruntable(true);

                 Color(10,15);cout<<"L'op"<<char (130)<<"ration est effectu"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);

            }
        }
         enregistrerdoc(listeDoc,"Documents.txt");
        if(!test)
           {Color(12,15);cout <<"Le document n'existe pas"<<endl;Color(0,15);}

cout<<"               Voulez vous faire une autre op"<<char (130)<<"ration:"<<endl;
cout<<"                   0-Non                      1-Oui"<<endl;
cout<<"                                 Choix: ";cin>>choice;
}while(choice==1);

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mediatheque::consulterCatalogueDocuments ()
{int choice;
  do{EnTete();liredocument(listeDoc,"Documents.txt");
    int l=listeDoc.size();
    for(int i=0;i<l;++i)
{
    cout<<listeDoc[i]->affiche();
}
cout<<"               Voulez vous sortir:"<<endl;
cout<<"                 0-Non           1-Oui"<<endl;
cout<<"                         Choix: ";cin>>choice;
}while(choice==0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mediatheque :: retirerDocument () // 1
{
int choice;
do{ liredocument(listeDoc,"Documents.txt");system("cls");
EnTete();
string code;
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;
//Livre*docu=new Livre;

vector <Doc*>::iterator it= listeDoc.begin();

bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==code)
            {
                test=true;
                listeDoc.erase (it+i);

                 Color(10,15);cout<<"Le document est retir"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);

            }
        }
         enregistrerdoc(listeDoc,"Documents.txt");
        if(!test)
           {Color(12,15);cout <<"Le document n'existe pas"<<endl;Color(0,15);}


cout<<"                Voulez vous retirer un autre document:"<<endl;
cout<<"                     0-Non              1-Oui"<<endl;
cout<<"                               Choix: ";cin>>choice;
}while(choice==1);


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mediatheque :: ajouterCategorieClient() // 2
{int choix;


do{lireclient(listeClient,"Clients.txt");date d;system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,7);cout <<"Le client n'existe pas"<<endl;Color(0,7);}
else
{
 cout<<"\nChoisir la categorie que vous souhaitez:"<<endl;
cout <<"1 -Client "<<char (133)<<" tarif reduit"<<endl;
cout <<"2 -Client "<<char (133)<<"tarif normal"<<endl;
cout <<"3 -Client abonn"<<char (130)<<endl;

cout<<"                           Choix :   ";
int choice;
cin>>choice;


switch (choice) {
//case 0 :gest_emp();
//break;
case 1 :{CategorieClient cat("TarifReduit",2,0,0.5 ,0.5, false ) ;pos->setcategorie(cat);
break;}
case 2 :{CategorieClient cat("TarifNormal",5,0,1,1 , false );pos->setcategorie(cat);
break ;}
case 3 :{CategorieClient cat("Abonne",10,30,0,2, false );pos->setcategorie(cat);
break;}
}

 //pos->setdaterenouv(d);

enregistrer(listeClient,"Clients.txt");
Color(10,15);cout<<"La Cat"<<char (130)<<"gorie est ajout"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);}
cout<<"                 Voulez vous ajouter une cat"<<char (130)<<"gorie a un autre client:"<<endl;
cout<<"                           0-Non                1-Oui"<<endl;
cout<<"                                      Choix: ";cin>>choix;
}while(choix==1);


}

void Mediatheque :: ajouterAudio() // 3   ( d le vector des documents )
{ int choice;
do{liredocument(listeDoc,"Documents.txt");lirelocalisation(listeLoc,"Localisations.txt");
system("cls");
EnTete();
        Audio*aud=new Audio();
    string classification,salle,rayon,genre;
    Localisation*loc=new Localisation;
    Genre*g=new Genre();
string cod,title,aut,year;
  cout<<"Donner le code de l'audio : " ; cin>>cod;
  cout<<"Donner le titre de l'audio : " ; cin>>title;
  cout<<"Donner l'auteur du l'audio : " ; cin>>aut;
  cout<<"Donner l'ann"<<char (130)<<"e de sortie de l audio : " ; cin>>year;
  cout<<"Donner la salle: ";cin>>salle;
  cout<<"Donner le rayon: ";cin>>rayon;
  cout<<"Donner le genre de l'audio: ";cin>>genre;
  cout<<"Donner la classification de l'audio : " ; cin>>classification;
  loc->set_rayon(rayon);loc->set_salle(salle);g->set_nom(genre);
  aud->setcode(cod);aud->settitre(title);aud->setauteur(aut);aud->setannee(year) ; aud->setclassification(classification) ;
  aud->setloc(*loc);aud->setgenre(*g);
vector <Localisation>::iterator it1=listeLoc.begin();
vector <Localisation>::iterator pos1= find(it1,listeLoc.end(),*loc);
if (pos1 == listeLoc.end()) {Color(12,15);cout <<"La localisation n'existe pas"<<endl;Color(0,15);}
else{
vector <Genre>::iterator it2=listeGenre.begin();
vector <Genre>::iterator pos2= find(it2,listeGenre.end(),*g);
if (pos2 == listeGenre.end()) ajouter(*g,"Genres.txt");

bool test=false;

        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==cod)
            {
                test=true;
                Color(12,15);cout <<"Le document existe deja"<<endl;Color(0,15);

            }
        }
        if(!test)
           {listeDoc.push_back(aud); ajouterdoc(aud,"Documents.txt");

        Color(10,15);cout <<"Le document est ajout"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);}



}
cout<<"                Voulez vous ajouter un autre document:"<<endl;
cout<<"                     0-Non               1-Oui"<<endl;
cout<<"                               Choix: ";cin>>choice;
}while(choice==1);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque :: ajouterLivre() // 4 ( d le vector des documents )
{ int choice;
do{liredocument(listeDoc,"Documents.txt");lirelocalisation(listeLoc,"Localisations.txt");
system("cls");EnTete();
Livre*l=new Livre();
string cod,title,aut,year; int nbrepage;string salle,rayon,genre,n;bool e1=false,e2=false;
Localisation*loc=new Localisation;
    Genre*g=new Genre();

  cout<<"Donner le code du livre : " ; cin>>cod;
  cout<<"Donner le titre du livre : " ; cin>>title;
  cout<<"Donner l'auteur du livre : " ; cin>>aut;
  cout<<"Donner l'ann"<<char (130)<<"e de sortie du livre : " ; cin>>year;
   cout<<"Donner la salle: ";cin>>salle;
  cout<<"Donner le rayon: ";cin>>rayon;
  cout<<"Donner le genre du livre: ";cin>>genre;
 // cout<<"Donner le nombre d exemplaires du livre : " ; cin>>ne;
  cout<<"Donner le nombre de pages du livre : " ; cin>>nbrepage;

//  Livre l(cod,title,aut,year,nbrepage) ;


l->setcode(cod);l->settitre(title);l->setauteur(aut);l->setannee(year);
//l->setnbEmprunts(nbem);
l->setempruntable(e1);l->setemprunte(e2);
loc->set_salle(salle);loc->set_rayon(rayon);l->setloc(*loc);g->set_nom(genre);l->setgenre(*g);
l->setnombrepage(nbrepage);
vector <Localisation>::iterator it1=listeLoc.begin();
vector <Localisation>::iterator pos1= find(it1,listeLoc.end(),*loc);
if (pos1 == listeLoc.end()) {Color(12,15);cout <<"La localisation n'existe pas"<<endl;Color(0,15);}
else{
vector <Genre>::iterator it2=listeGenre.begin();
vector <Genre>::iterator pos2= find(it2,listeGenre.end(),*g);
if (pos2 == listeGenre.end()) ajouter(*g,"Genres.txt");


  bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==l->getcode())
            {
                test=true;
                Color(12,15);cout <<"Le document existe deja"<<endl;Color(0,15);

            }
        }
        if(!test)
           {listeDoc.push_back(l); ajouterdoc(l,"Documents.txt");
            Color(10,15);cout <<"Le document est ajout"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);}

}
cout<<"                Voulez vous ajouter un autre document:"<<endl;
cout<<"                      0-Non              1-Oui"<<endl;
cout<<"                               Choix: ";cin>>choice;
}while(choice==1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mediatheque :: ajouterVideo() //5  ( d le vector des documents )
{int choice;
do{liredocument(listeDoc,"Documents.txt");lirelocalisation(listeLoc,"Localisations.txt");
system("cls");EnTete();
Video* vid=new Video();
    string cod,title,aut,year; int dureeee ;string m,salle,rayon,genre;bool e1=false,e2=false;
    Localisation*loc=new Localisation;
    Genre*g=new Genre();

cout <<"Donner le code de la vid"<<char (130)<<"o :";cin>>cod;
cout <<"Donner le nom de la vid"<<char (130)<<"o :";cin>>title;
cout <<"Donner l'auteur de la vid"<<char (130)<<"o : ";cin>>aut;
cout <<"Donner l'ann"<<char(130)<<"e de la vid"<<char (130)<<"o :";cin>>year;
cout<<"Donner la salle: ";cin>>salle;
cout<<"Donner le rayon: ";cin>>rayon;
cout<<"Donner le genre de la vid"<<char (130)<<"o: ";cin>>genre;
cout <<"Donner la dur"<<char(130)<<"e de la vid"<<char (130)<<"o :";cin>>dureeee;
cout <<"Donner la mention de la vid"<<char (130)<<"o :";cin>>m;

vid->setcode(cod);vid->settitre(title);vid->setauteur(aut);vid->setannee(year);
loc->set_rayon(rayon);loc->set_salle(salle);g->set_nom(genre);
vid->setloc(*loc);vid->setgenre(*g);
vid->setdureefilm(dureeee); vid->setmentionlegale(m);vid->setempruntable(e1);
vid->setemprunte(e2);

vector <Localisation>::iterator it1=listeLoc.begin();
vector <Localisation>::iterator pos1= find(it1,listeLoc.end(),*loc);
if (pos1 == listeLoc.end()) {Color(12,15);cout <<"La localisation n'existe pas"<<endl;Color(0,15);}
else{
vector <Genre>::iterator it2=listeGenre.begin();
vector <Genre>::iterator pos2= find(it2,listeGenre.end(),*g);
if (pos2 == listeGenre.end()) ajouter(*g,"Genres.txt");

  bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==vid->getcode())
            {
                test=true;
               Color(12,15);cout <<"Le document existe deja"<<endl;Color(0,15);

            }
        }
        if(!test)
            {listeDoc.push_back(vid); ajouterdoc(vid,"Documents.txt");
            Color(10,15);cout <<"Le document est ajout"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);}
}
cout<<"                 Voulez vous ajouter un autre document:"<<endl;
cout<<"                        0-Non             1-Oui"<<endl;
cout<<"                                 Choix: ";cin>>choice;
}while(choice==1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque :: inscrireClient ()
{ int choice;
do{Client*cl=new Client();system("cls");EnTete();
lireclient(listeClient,"Clients.txt");


     string name,prename,adres ; date dateINS,dateRENOUV;
//int nbEmpEff,nbEmpDep,nbEmpCours,
int codeRed;
//bool Late;
cout <<"Donner le nom du client est: ";cin>>name;
cout <<"Donner le pr"<<char (130)<<"nom du client est: ";cin>>prename;
cout <<"Donner l'adresse du client est: ";cin>>adres;
cout <<"Donner la date d'inscription: ";cin>>dateINS;
cout <<"Donner la date renouvellement: ";cin>>dateRENOUV;
//cout <<"Donner le nombre d emprunts effectués :";cin>>nbEmpEff;
//cout <<"Donner lenombre d emprunts depassés :";cin>>nbEmpDep;
//cout <<"Donner le nombre d emprunts en cours :";cin>>nbEmpCours;
cout <<"Donner le code de r"<<char (130)<<"duction: ";cin>>codeRed;


cl->setnom(name);cl->setprenom(prename);cl->setadresse(adres);cl->setdateinsc(dateINS);
cl->setdaterenouv(dateRENOUV);
//cl->setnbEmpruntsEffectues(nbEmpEff);cl->setnbEmpruntsDepasses(nbEmpDep);cl->setnbEmpruntsEncours(nbEmpCours);
cl->setcodeReduction(codeRed);

vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end())
   {listeClient.push_back(*cl);
    Color(10,15);cout <<"Le client est ajout"<<char (130)<<" avec succ"<<char (130)<<"s"<<endl;Color(0,15);
    ajouter(*cl,"Clients.txt");
   }
else
    {Color(12,15);cout <<"Le client est d"<<char (130)<<"j"<<char (133)<<"existant"<<endl;Color(0,15);}

cout<<"                 Voulez vous inscrire un autre client:"<<endl;
cout<<"                       0-Non             1-Oui"<<endl;

cout<<"                                 Choix:";cin>>choice;
}while(choice==1);

    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque ::changerCategorieClient ()
{int choice;

do{lireclient(listeClient,"Clients.txt");system("cls");EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"le client n'existe pas"<<endl;Color(0,15);}
else
{
cout<<"Choisir la cat"<<char (130)<<"gorie que vous souhaitez:"<<endl;
cout <<"1 -Client "<<char (133)<<"tarif reduit"<<endl;
cout <<"2 -Client "<<char (133)<<"tarif normal"<<endl;
cout <<"3 -Client abonn"<<char (130)<<""<<endl;

cout<<"                           Choix :   ";
int choix;
cin>>choix;

switch (choix) {

case 1 :{CategorieClient cat("TarifReduit",2,0,0.5 ,0.5, false ) ;pos->setcategorie(cat);
break;}
case 2 :{CategorieClient cat("TarifNormal",5,0,1,1 , false );pos->setcategorie(cat);
break ;}
case 3 :{CategorieClient cat("Abonne",10,30,0,2, false );pos->setcategorie(cat);
break;}
}
enregistrer(listeClient,"Clients.txt");
Color(10,15);cout <<"La cat"<<char (130)<<"gorie est chang"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);}


cout<<"            Voulez vous changer la cat"<<char (130)<<"gorie d'un autre client:"<<endl;
cout<<"                     0-Non                      1-Oui"<<endl;

cout<<"                                  Choix: ";cin>>choice;
}while(choice==1);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mediatheque :: afficherCaracteristiquesClient ()
{int choix;
do{lireclient(listeClient,"Clients.txt");EnTete();
int l=listeClient.size();
    for(int i=0;i<l;++i)
{
    cout<<listeClient[i].affiche()<<endl;

}
cout<<"         Voulez vous sortir"<<endl;
cout<<"          0-Non          1-Oui"<<endl;

cout<<"                  Choix: ";cin>>choix;

}while(choix==0);
/*cout <<"le nom du client est"<<cl.getnom()<<endl;
cout <<"le prenom du client est"<<cl.getprenom()<<endl;
cout <<"l adresse du client est"<<cl.getadresse()<<endl;*/

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque :: renouvelerInscriptionClient ()
{int choix;


do{lireclient(listeClient,"Clients.txt");date d;system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else
{
d.getdateactuel ();
date da;da.getdateactuel();
d=d.adddate(365) ;
lireclient(listeClient,"Clients.txt");
if (pos->getdaterenouv()<da || (pos->getdaterenouv()<da && da<pos->getdaterenouv()) )
{
CategorieClient cat1 ("Abonne",10,30,0,2, false );
CategorieClient cat2 ("TarifReduit",2,0,0.5 ,0.5, false );
CategorieClient cat3 ("TarifNormal",5,0,1,1 , false );

cout <<"0 -Le Client a donn"<<char (130)<<" une justificatif"<<endl;
cout <<"1 -Le Client n'a pas donn"<<char (130)<<" une justificatif"<<endl;
cout<<"                        Choix :   ";
int choice;
cin>>choice;
switch (choice)
{
case 0: {if (pos->getcategorie().get_nomCat()==cat1.get_nomCat())  pos->setcategorie(cat3);
         if (pos->getcategorie().get_nomCat()==cat2.get_nomCat())  pos->setdaterenouv(d);
}
case 1: pos->setcategorie(cat3);
}
Color(10,15);cout<<"Inscription renouvel"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);
}
else{Color(12,7);cout <<"\nLa date de renouvellement d'inscription est depass"<<char (130)<<"e"<<endl;Color(0,15);}


 //pos->setdaterenouv(d);

enregistrer(listeClient,"Clients.txt");}
cout<<"                 Voulez vous renouveler l'inscription d'un autre client:"<<endl;
cout<<"                           0-Non                1-Oui"<<endl;
cout<<"                                      Choix: ";cin>>choix;
}while(choix==1);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque ::bloquerClient()
{date dac;dac.getdateactuel();
lireclient(listeClient,"Clients.txt");
lirefiche(listeFiche,"Fiches.txt");
 for( unsigned int i=0; i<listeClient.size(); i++)
{date d=listeClient[i].getdaterenouv();
    if (d<dac )
listeClient[i].setenRetard(true);
}
 for( unsigned int i=0; i<listeFiche.size(); i++)
 {if (listeFiche[i]. verifier_les_emprunts ()==1)
  {for( unsigned int j=0; i<listeClient.size(); j++)
   {if(*listeFiche[i].get_cli()==listeClient[j])
       {listeClient[i].setenRetard(true);
        listeClient[i].incnbEmpruntsDepasses();}
   }

 }
 }
 enregistrer(listeClient,"Clients.txt");

}

//////////////////////////////////////////////////////////////////////////////////
void Mediatheque ::debloquerClient()
{int choix;

do{lireclient(listeClient,"Clients.txt");system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,7);cout <<"Le client n'existe pas"<<endl;Color(0,7);}
else
{

        pos->setenRetard(false);

   enregistrer(listeClient,"Clients.txt");
   Color(10,15);cout<<"Client debloqu"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);}
cout<<"             Voulez vous debloquer un autre client:"<<endl;
cout<<"                       0-Non          1-Oui "<<endl;
cout<<"                              Choix:";cin>>choix;
}while(choix==1);

}

////////////////////////////////////////////////////////////////////////////////////

void Mediatheque :: supprimerCategorieClient()
    {int choix;

do{lireclient(listeClient,"Clients.txt");system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,7);cout <<"Le client n'existe pas"<<endl;Color(0,7);}
else
{
    CategorieClient c("X");
        pos->setcategorie(c);

   enregistrer(listeClient,"Clients.txt");
   Color(10,15);cout<<"La cat"<<char (130)<<"gorie est supprim"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);}
cout<<"             Voulez vous supprimer la cat"<<char (130)<<"gorie d'un autre client:"<<endl;
cout<<"                       0-Non          1-Oui "<<endl;
cout<<"                              Choix:";cin>>choix;
}while(choix==1);


    }


////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque :: modifierCategorieClient () // catcl2 est la nouvelle
{
     int choix;


do{lireclient(listeClient,"Clients.txt");date d;system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else
{
d.getdateactuel ();
date da;da.getdateactuel();
d=d.adddate(365) ;
lireclient(listeClient,"Clients.txt");
if (pos->getdaterenouv()<da || (pos->getdaterenouv()<da && pos->getdaterenouv()<da) )
{
CategorieClient cat1 ("Abonne",10,30,0,2, false );
CategorieClient cat2 ("TarifReduit",2,0,0.5 ,0.5, false );
CategorieClient cat3 ("TarifNormal",5,0,1,1 , false );

cout<<"\nChoisir la categorie que vous souhaitez:"<<endl;
cout <<"1 -Client "<<char (133)<<"tarif reduit"<<endl;
cout <<"2 -Client "<<char (133)<<"tarif normal"<<endl;
cout <<"3 -Client abonn"<<char (130)<<endl;

cout<<"                           Choix :   ";
int choice;
cin>>choice;
switch (choice)
{
case 1:  pos->setcategorie(cat2);break;
case 2: pos->setcategorie(cat3);break;
case 3:pos->setcategorie(cat1);break;
}
Color(10,15);cout<<"La cat"<<char (130)<<"gorie est modifi"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);}

else {Color(12,15);cout <<"\nLa date de renouvellement d'inscription est depass"<<char (130)<<"e"<<endl;Color(0,15);}
 //pos->setdaterenouv(d);

enregistrer(listeClient,"Clients.txt");
}
cout<<"                 Voulez vous renouveler l'inscription d'un autre client:"<<endl;
cout<<"                           0-Non                1-Oui"<<endl;
cout<<"                                      Choix: ";cin>>choix;
}while(choix==1);

}
////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::resilierClient ()////////////////////////////////////////////
{int choix;

do{lireclient(listeClient,"Clients.txt");system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else
{
listeClient.erase(pos);
 Color(10,15);cout<<"Client resili"<<char (130)<<" avec succ"<<char (138)<<"s"<<endl;Color(0,15);

enregistrer(listeClient,"Clients.txt");}
cout<<"             Voulez vous resilier un autre client:"<<endl;
cout<<"                    0-Non            1-Oui"<<endl;

cout<<"                               Choix:";cin>>choix;
}while(choix==1);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque :: changerAdresseClient()/////////////////////////////////////////////////////////////////////////
{int choix;

  do{lireclient(listeClient,"Clients.txt");system("cls");
  EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else
{
    string ch;
    cout<<"Donner la nouvelle adresse: ";
    cin>>ch;

    pos->setadresse(ch);Color(10,15);cout<<"Adresse chang"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);
}
enregistrer(listeClient,"Clients.txt");
cout<<"                Voulez vous changer une autre adresse:"<<endl;
cout<<"                        0-Non              1-Oui"<<endl;
cout<<"                                  Choix:";cin>>choix;
}while(choix==1);

}

///////////////////////////////////////////////////////////////////////////////////
void Mediatheque::restituerDocument ()////////???????????????????????????????
{int choix;

do{liredocument(listeDoc,"Documents.txt");system("cls");
EnTete();
lireclient(listeClient,"Clients.txt");
string code;
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else{
pos->decnbEmpruntsEncours();

bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==code)
            {test=true;
       listeDoc[i]->setemprunte(false);

          Color(10,15);cout<<"L'operation est effectu"<<char (130)<<"e avec succ"<<char (138)<<"s"<<endl;Color(0,15);}}
        if(!test)
           {Color(12,15);cout <<"Le document n'existe pas"<<endl;Color(0,15);}}


enregistrerdoc(listeDoc,"Documents.txt");
enregistrer(listeClient,"Clients.txt");
cout<<"          Voulez vous restituer un autre document:"<<endl;
cout<<"             0-Non                    1-Oui"<<endl;

cout<<"                          Choix:";cin>>choix;
}while(choix==1);

}

////////////////////////////////////////////////////////////////////////////////////
Doc* Mediatheque::chercherdoc()
{string code;
liredocument(listeDoc,"Documents.txt");
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;

 for(unsigned int i = 0; i < listeDoc.size(); i++)
    { if(listeDoc[i]->getcode()==code) return listeDoc[i];}

Color(12,1);cout<<"Document non existant";Color(15,1);return NULL;
}
//////////////////////////////////////////////////////////////////////////////////////////
Client Mediatheque::chercherclient()
{string nom,prenom,adresse;
lireclient(listeClient,"Clients.txt");
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client cl(nom,prenom,adresse);
for( unsigned int j=0; j<listeClient.size(); j++)
   {if(cl==listeClient[j]) return listeClient[j];}
Color(12,1);cout<<"Client non existant";Color(15,1);return cl;
}
/////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::emprunterDocument ()
{int choix;
    do{lireclient(listeClient,"Clients.txt");system("cls");
    EnTete();
liredocument(listeDoc,"Documents.txt");
liregenre(listeGenre,"Genres.txt");
string code;
cout<<"Donner le code du document que vous recherchez: ";
cin>>code;
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else{
if(pos->getenRetard()==false)
{bool test=false;
        for( unsigned int i=0; i<listeDoc.size(); i++)
        {
            if(listeDoc[i]->getcode()==code)
            {test=true;

if(listeDoc[i]->getempruntable()==true)
{if(listeDoc[i]->getemprunte()==false)
{if(pos->getcategorie().get_nbEmpruntsMax()>pos->getnbEmpruntsEffectues())
{FicheEmprunt*fiche=new FicheEmprunt;
fiche->set_cli(&(*pos));fiche->set_docu(listeDoc[i]);fiche->calculer_le_tarif();fiche->set_dateEmprunt();
fiche->set_dateLimite();fiche->set_dateRappel();
pos->incnbEmpruntsEffectues();pos->incnbEmpruntsEncours();pos->ajouterfiche(*fiche);
listeDoc[i]->setemprunte(true);int nb=listeDoc[i]->getnbEmprunts()+1;listeDoc[i]->setnbEmprunts(nb);
vector <Genre>::iterator it2=listeGenre.begin();
vector <Genre>::iterator pos2= find(it2,listeGenre.end(),listeDoc[i]->getgenre());

pos2->set_nbEmprunts(pos2->get_nbEmprunts()+1);
enregistrer(listeGenre,"Genres.txt");


listeFiche.push_back(*fiche);ajouter(*fiche,"Fiches.txt");
Color(10,15);cout<<"L'operation est effectu"<<char (130)<<"e avec succ"<<char (130)<<"s"<<endl;Color(0,15);
}
    else {Color(12,15);cout<<"Desol"<<char (130)<<", le nombre maximal d'emprunts est atteint";Color(0,15);}
}
    else {Color(12,15);cout<<"Desol"<<char (130)<<", le document est d"<<char (130)<<"j"<<char (133)<<" emprunt"<<char (130)<<endl;Color(0,15);}
}
    else {Color(12,15);cout<<"Document consultable";Color(0,15);}
}}
 if(!test)
           {Color(12,15);cout <<"Le document n'existe pas"<<endl;Color(0,15);}
}

else {Color(12,15);cout<<"Client en retard de restitution";Color(0,15);}
        }
enregistrer(listeClient,"Clients.txt");
enregistrerdoc(listeDoc,"Documents.txt");
cout<<"\n             Voulez vous emprunter un autre document:"<<endl;
cout<<"                     0-Non                1-Oui"<<endl;

cout<<"                                Choix:";cin>>choix;
}while(choix==1);

}

//////////////////////////////////////////////////////////////////////
void Mediatheque::consulterEmpruntsClient ()
{int choix;
do{lireclient(listeClient,"Clients.txt");
system("cls");
EnTete();
string nom,prenom,adresse;
cout<<"Donner le nom du client que vous recherchez: ";
cin>>nom;
cout<<"Donner le pr"<<char (130)<<"nom du client que vous recherchez: ";
cin>>prenom;
cout<<"Donner l'adresse du client que vous recherchez: ";
cin>>adresse;
Client*cl=new Client;cl->setadresse(adresse);cl->setnom(nom);cl->setprenom(prenom);
vector <Client>::iterator it=listeClient.begin();
vector <Client>::iterator pos= find(it,listeClient.end(),*cl);
if (pos == listeClient.end()) {Color(12,15);cout <<"Le client n'existe pas"<<endl;Color(0,15);}
else
{cout <<"Les emprunts du client sont: "<<endl;
lirefiche(listeFiche,"Fiches.txt");

for (unsigned int i=0;i<listeFiche.size();i++)
{  if(*(listeFiche[i].get_cli())==*pos)

    cout<<listeFiche[i].affiche()<<endl;
}
}
cout<<"                 Voulez vous chercher les emprunts d'un autre client :"<<endl;
cout<<"                           0-Non                1-Oui"<<endl;
cout<<"                                      Choix: ";cin>>choix;
}while(choix==1);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mediatheque::afficherStatistiques ()
{int choix;
do{liregenre(listeGenre,"Genres.txt");int somme=0;
system("cls");
EnTete();
for(unsigned int i=0;i<listeGenre.size();++i)
    somme+=listeGenre[i].get_nbEmprunts();

//vector<Genre>::iterator it=listeGenre.begin();
sort(listeGenre.begin(),listeGenre.end());
for(unsigned int i=0;i<listeGenre.size();++i)
{cout<<setprecision(3);
cout<<"Le pourcentage d'emprunt du genre "<<listeGenre[i].get_nom()<<": "<<(float)100*listeGenre[i].get_nbEmprunts()/somme<<"%"<<endl;}

cout<<"Le genre le plus emprunt"<<char (130)<<" est: "<<listeGenre[listeGenre.size()-1].get_nom()<<"."<<endl;


cout<<"               Voulez vous sortir :"<<endl;
cout<<"                  0-Non       1-Oui"<<endl;
cout<<"                        Choix: ";cin>>choix;
}while(choix==0);

}



