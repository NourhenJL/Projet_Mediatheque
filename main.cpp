#include <iostream>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include"Mediatheque.h"
#include"Localisation.h"
#include"Genre.h"
#include"Doc.h"
#include"Livre.h"
#include"Client.h"
#include<string>
#include"CategorieClient.h"

#include <cstdlib>
#include"main.h"
#include"fichier.h"


using namespace std;






//***********************Gestion du Client*******************************

void gest_client (Mediatheque m)
{
EnTete();

cout <<"1 -Ajouter la cat"<<char (130)<<"gorie du client                  "<<endl;
cout <<"2 -Modifier la cat"<<char (130)<<"gorie du client                 "<<endl;
cout <<"3 -Supprimer la cat"<<char (130)<<"gorie du client                "<<endl;
cout <<"4 -Inscrire un client                              "<<endl;
cout <<"5 -Changer le cat"<<char (130)<<"gorie du client                  "<<endl;
cout <<"6 -Afficher les caract"<<char (130)<<"ristiques du client         "<<endl;
cout <<"7 -Modifier les caract"<<char (130)<<"ristiques du client         "<<endl;
cout <<"8 -Renouveler l'inscription du client              "<<endl;
cout <<"9 -Resilier client                                 "<<endl;
cout <<"10-Changer l'adresse du client                     "<<endl;
cout <<"11-Consulter les emprunts client                   "<<endl;
cout <<"12-Bloquer client                                  "<<endl;
cout<<"13-D"<<char(130)<<"bloquer client                                "<<endl;
cout <<"0 -Retour"<<endl;
cout<<"                           Choix :   ";
int choix  ;  cin>>choix  ;
system ("cls");
Client cl;
switch (choix)
{ case 0 : menu_emp(m); break ;
case 1 :{m.ajouterCategorieClient(); system("cls");gest_client(m); break ; }
case 2 : {m.modifierCategorieClient();system("cls");gest_client(m);break; }
case 3 :{m.supprimerCategorieClient();system("cls");gest_client(m);break; }
case 4 : { m.inscrireClient();system("cls");gest_client(m);break ;}
case 5 :{m.changerCategorieClient();system("cls");gest_client(m);break ;}
case 6 :{  m.afficherCaracteristiquesClient();//Sleep(8000);
system("cls");gest_client(m);break ;}
//case 7 :{ Client cl ; m.modifierCaracteristiquesClient(cl);system("cls");gest_client(m);break ;} // dev de modif
case 8 :{ m.renouvelerInscriptionClient();system("cls");gest_client(m);break ;}
case 9 :m.resilierClient();system("cls");gest_client(m);break;
case 10 :m.changerAdresseClient();gest_client(m);
break ;
case 12:m.bloquerClient() ; system("cls");gest_client(m); break  ;
case 13:m.debloquerClient(); system("cls");gest_client(m);break  ;
case 11 :m.consulterEmpruntsClient(); system("cls");gest_client(m);break  ;
default : gest_client(m);
}
}
//***********************Gestion du document*******************************
void gest_doc (Mediatheque m)
{
EnTete();
cout <<"1 -Ajouter un Audio                     "<<endl;
cout <<"2 -Ajouter un Livre                     "<<endl;
cout <<"3 -Ajouter un Vid"<<char (130)<<"o                     "<<endl;
cout <<"4 -Rendre le document consultable       "<<endl;
cout <<"5 -Rendre le document empruntable       "<<endl;
cout <<"6 -Retirer le document                  "<<endl;
cout <<"7 -Emprunter le document                "<<endl;
cout <<"8 -Restituer le document                "<<endl;
cout <<"0 -Retour"<<endl;
cout<<"                           Choix :   ";
int choix;
cin>>choix;
Client cl;


switch (choix)
{
case 0 :/*menupr();*/ menu_emp(m) ;
break;
case 1 :{  m.ajouterAudio()  ; system("cls") ;gest_doc(m) ; break ;}
case 2 : { m.ajouterLivre()  ; system("cls") ; gest_doc(m) ;  break ;}
case 3 : { m.ajouterVideo()  ; system("cls") ;gest_doc(m) ; break ;}
case 4 :{ m.rendreConsultableDocument() ; system("cls") ; gest_doc(m) ;  break ;}
case 5 : { m.rendreEmpruntableDocument() ; system("cls") ; gest_doc(m) ;   break ; }
case 6 : {m.retirerDocument()  ; system("cls") ; gest_doc(m) ;  break; }
case 7 :{ m.emprunterDocument(); system("cls") ; gest_doc(m) ; break;}
case 8 :{  m.restituerDocument();system("cls") ; gest_doc(m) ; break ;}
//default : gest_emp();
}
}
//*****************************************************************
void menu_emp(Mediatheque m)
{ string m1;
   EnTete();
cout <<"1 -Gestion du client                    "<<endl;
cout <<"2 -Gestion du document                  "<<endl;
cout <<"3 -Trouver les emprunts en retard       "<<endl;
cout <<"4 -Afficher les statistiques            "<<endl;
cout <<"5 -Consulter le catalogue des documents "<<endl;
cout <<"0 -Retour"<<endl;
cout<<"                           Choix :   ";
int choix  ;  cin>>choix  ;
system("cls");
switch (choix)

{  case 0 : menupr(m) ; break ;
   case 1 :gest_client(m) ;  break ;
   case 2 :gest_doc(m)    ;  break ;
   case 3 : {m.trouverEmpruntsEnRetard() ; system("cls") ;menu_emp(m) ;  break;}
   case 4 :m.afficherStatistiques()  ;system("cls") ;menu_emp(m) ;  break ;
   case 5 :{m.consulterCatalogueDocuments()  ;  system("cls") ; menu_emp(m)  ;  break;}
   default : menu_emp(m) ;
} }

//***************** Fonction qui permet diafficher le menu client *****************
void menuclient (Mediatheque m)
{
//Client c;
EnTete();
//cout<<"1-bloquer debloquer"<<endl;
//cout<<"2-pouvoir emprunter"<<endl;
cout<<"1-changer une adresse                    :"<<endl;
cout<<"0-Retour"<<endl;
cout<<"                      Choix :   ";
int choix  ;  cin >>choix  ;
system ("cls");
switch (choix)
{  case 0:menupr (m) ;  break  ;
case 1:{ m.changerAdresseClient(); system("cls");menuclient(m); break  ;}
//case 2:m.debloquer (); break  ;
//case 3:c.pouvoir_emprunter();

default : menuclient (m); } }
//***************** Fonction qui permet au client de saisir un mot de passe pour acceder au menu *****************
void mdpass()
{string mdp,ch="password";
   do
    {EnTete();
        cout <<"                           Mot de passe : ";
cin >>mdp;
}while( mdp!=ch) ;
}

//*********************************************************
void  menupr (Mediatheque m)
{   int c ;
    EnTete();
do{
cout<<"                      Bienvenue dans la Mediatheque                  ";
cout<<"\n\n\n\t\t         Espace Employ"<<char (130)<<"............1\n\t\t         Espace client ............2\n";
cout<<"                                                              Choix : ";
cin>>c ;
system("cls");
}while ((c!=1)&&(c!=2)) ;
switch (c)
{
case 1 :mdpass();menu_emp(m)  ;// Il faut utiliser un mot de passe pour acceder au menu employé
break ;
case 2 :system("cls") ;menuclient(m); break;
default : system("cls") ;menupr (m);
// Le controle de saisie
do{
cout<<"                      Bienvenue dans la Mediatheque                   ";
cout<<"n\n\n\t\t         Espace employ"<<char (130)<<" ............1\n\t\t         Espace client ...........2\n";
cout<<"                                                              Choix : ";
cin>>c;
EnTete();
}while ((c!=1)&&(c!=2)) ;
}
}
//***************************************************************************************************


int main()
{  EnTete() ;
Livre l1("ok","ok","np","glass",500);
Localisation loc("lecture","12");Genre g("Bigdramashow");//Localisation*loc1=&loc;Genre*g1=&g;
l1.setloc(loc);l1.setgenre(g);

//cout<<l.affiche();
vector<Doc*> vd;vd.push_back(&l1);
vector<Doc*> v;
//enregistrerdoc(vd,"livre.txt");
//liredocument(v,"Documents.txt");

//ajouter(v,"livre.txt");
//cout<<v[0]->affiche();
/*vector <Doc*>::iterator it= v.begin();
vector <Doc*>::iterator *pos= find(it,v.end(),docu);
if (pos == v.end()) {Color(12,15);cout <<"le document n existe pas"<<endl;Color(0,15);}
else{cout<<"ok";}*/

CategorieClient cat("tarifreduit");
Client cl("m","a","patata");
cl.setcategorie(cat);
vector<Client> client;vector<Client> client1;
client.push_back(cl);
//enregistrerclien(client,"client.txt");
//lireclient(client1,"Clients.txt");
//for(unsigned int i=0;i<3;++i)
  //  ajouter(cl,"Clients.txt");
//cout<<client1[i].affiche();


FicheEmprunt fiche(true,20) ; //fiche.set_dateEmprunt() ;
fiche.set_cli(&cl) ;
fiche.set_docu(&l1);
vector<FicheEmprunt> fe;fe.push_back(fiche);
vector<FicheEmprunt> vf;
//enregistrer(fe,"Fiches.txt");
//lirefiche(vf,"Fiches.txt");
//ajouter(fiche,"fiche.txt");
//for(unsigned int i=0;i<vf.size();++i)
//cout<<vf[i].affiche();
//Color(10,15); cout<<"ok";
/*ifstream f;

date dateE ,dateL ,dateR  ;bool depa;double tar ;
string ch,separateur1,separateur2,separateur;

string name ,pren,adr;int nbEmpruntsEff,nbEmpruntsDep,nbEmpruntsEnc,codeR;bool Retard;
string nom;int nbEmpruntsMaxi;double cot,coefT,coefd ; bool codeRedactif;CategorieClient categorie;

Localisation lc;Genre gr;
string cod,title,aut,year; int nbem,ne,nbrepage,duree;string sa,ray,n,classif,mention;bool e1,e2;
//Livre l;
f.open("fiche.txt");
if(f)
{
while(f>>ch)
{ if (ch=="Fiche")
 { FicheEmprunt*fe=new FicheEmprunt();
 //Client*cl=new Client();


     f>>dateE>>dateL>>dateR>>depa>>tar>>separateur>>name>>pren>>adr>>nbEmpruntsEff>>nbEmpruntsDep>>nbEmpruntsEnc>>codeR>>Retard>>nom>>nbEmpruntsMaxi>>cot>>coefT>>coefd>>codeRedactif>>separateur;
fe->setdateLimite(dateL);fe->setdateEmprunt(dateE);fe->setdateRappel(dateR);
fe->set_depassee(depa);
fe->set_tarif(tar);
vf.push_back(*fe);

 }}}
 cout<<dateL<<" "<<dateE<<" "<<dateR<<" "<<depa<<" "<<tar<<endl;
 cout<<nom;
 cout<<separateur;*/
 //cout<<vf[0].get_docu()->getauteur();

//cin>>d;
//cout<<d;*/


Mediatheque m ;
menupr(m);

    return 0;

}
