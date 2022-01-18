#include "fichier.h"




void enregistrerdoc(vector<Doc*> v,string const nomf)
 {ofstream f;int l=v.size();
 f.open(nomf.c_str(),ios::trunc);
 if(f)
 {
 for(int i=0;i<l;++i)
    f<<v[i]->affichefich()<<endl;

}
else cout<<"erreur";
f.close();
 }


void ajouterdoc(Doc* d,string const nomf)
{ofstream f;
 f.open(nomf.c_str(),ios::app);
 if(f)
 {
    f<<d->affichefich()<<endl;

}
else cout<<"erreur";
f.close();
}

void liredocument(vector<Doc*>&v,string const nomf)
{ifstream f;
Localisation lc;Genre gr;
string cod,title,aut,year; int nbem,ne,nbrepage,duree;string sa,ray,n,classif,mention;bool e1,e2;
string ch;
v.clear();
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{

if(ch=="Livre")
{
Livre*l=new Livre();
 f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>nbrepage;
l->setcode(cod);l->settitre(title);l->setauteur(aut);l->setannee(year);l->setnbEmprunts(nbem);l->setempruntable(e1);l->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);l->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);l->setgenre(gr);l->setnombrepage(nbrepage);
v.push_back(l);

}

 if(ch=="Audio")

{Audio*a=new Audio();

 f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>classif;

   a->setcode(cod);a->settitre(title);a->setauteur(aut);a->setannee(year);a->setnbEmprunts(nbem);a->setempruntable(e1);a->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);a->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);a->setgenre(gr);a->setclassification(classif);
v.push_back(a);}
if(ch=="Video")
  {//f.seekg(5, ios::cur);
Video*vid=new Video();
    f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>duree>>mention;
vid->setcode(cod);vid->settitre(title);vid->setauteur(aut);vid->setannee(year);vid->setnbEmprunts(nbem);vid->setempruntable(e1);vid->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);vid->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);vid->setgenre(gr);vid->setdureefilm(duree);vid->setmentionlegale(mention);
v.push_back(vid);}
}

}
else cout<<"erreur";
f.close();
}
void lireclient(vector<Client>&v,string const nomf)
{
ifstream f;
v.clear();
string name ,pren,adr;int nbEmpruntsEff,nbEmpruntsDep,nbEmpruntsEnc,codeR;bool Retard;
string nom;int nbEmpruntsMaxi;double cot,coefT,coefd ; bool codeRedactif;
CategorieClient categorie;
date dateinsc,daterenouv;
string ch;
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{ if (ch=="Client")
 { Client*cl=new Client();
     f>>name>>pren>>adr>>dateinsc>>daterenouv>>nbEmpruntsEff>>nbEmpruntsDep>>nbEmpruntsEnc>>codeR>>Retard>>nom>>nbEmpruntsMaxi>>cot>>coefT>>coefd>>codeRedactif;
cl->setnom(name);cl->setprenom(pren);cl->setadresse(adr);cl->setnbEmpruntsEffectues(nbEmpruntsEff);cl->setnbEmpruntsDepasses(nbEmpruntsDep);
cl->setnbEmpruntsEncours(nbEmpruntsEnc);cl->setcodeReduction(codeR);cl->setenRetard(Retard);
cl->setdateinsc(dateinsc);cl->setdaterenouv(daterenouv);

categorie.set_nomCat(nom);categorie.set_nbEmpruntsMax(nbEmpruntsMaxi);categorie.set_cotisation(cot);
categorie.set_coefTarif(coefT);categorie.set_coefduree(coefd);categorie.set_codedReductionactif(codeRedactif);
cl->setcategorie(categorie);

v.push_back(*cl);
 }
}
}
else cout<<"erreur";
}


void lirefiche(vector<FicheEmprunt>&v,string const nomf)
{ifstream f;
v.clear();
date dateE ,dateL ,dateR  ;bool depa;double tar ;
string ch,separateur,separateur2;

string name ,pren,adr;int nbEmpruntsEff,nbEmpruntsDep,nbEmpruntsEnc,codeR;bool Retard;
string nom;int nbEmpruntsMaxi;double cot,coefT,coefd ; bool codeRedactif;CategorieClient categorie;
date dateinsc,daterenouv;


Localisation lc;Genre gr;
string cod,title,aut,year; int nbem,ne,nbrepage,duree;string sa,ray,n,classif,mention;bool e1,e2;
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{ if (ch=="Fiche")
 { FicheEmprunt*fe=new FicheEmprunt();
 Client*cl=new Client();


     f>>dateE>>dateL>>dateR>>depa>>tar>>separateur>>name>>pren>>adr>>dateinsc>>daterenouv>>nbEmpruntsEff>>nbEmpruntsDep>>nbEmpruntsEnc>>codeR>>Retard>>nom>>nbEmpruntsMaxi>>cot>>coefT>>coefd>>codeRedactif>>separateur;
fe->setdateLimite(dateL);fe->setdateEmprunt(dateE);fe->setdateRappel(dateR);fe->set_depassee(depa);
fe->set_tarif(tar);

cl->setnom(name);cl->setprenom(pren);cl->setadresse(adr);cl->setnbEmpruntsEffectues(nbEmpruntsEff);cl->setnbEmpruntsDepasses(nbEmpruntsDep);
cl->setnbEmpruntsEncours(nbEmpruntsEnc);cl->setcodeReduction(codeR);cl->setenRetard(Retard);
categorie.set_nomCat(nom);categorie.set_nbEmpruntsMax(nbEmpruntsMaxi);categorie.set_cotisation(cot);
categorie.set_coefTarif(coefT);categorie.set_coefduree(coefd);categorie.set_codedReductionactif(codeRedactif);
cl->setcategorie(categorie);cl->setdateinsc(dateinsc);cl->setdaterenouv(daterenouv);

fe->set_cli(cl);
//f.seekg(ios::cur);
//f>>separateur2;
if(separateur=="Livre")
{Livre*l=new Livre();


 f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>nbrepage;
l->setcode(cod);l->settitre(title);l->setauteur(aut);l->setannee(year);l->setnbEmprunts(nbem);l->setempruntable(e1);l->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);l->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);l->setgenre(gr);l->setnombrepage(nbrepage);
fe->set_docu(l);
}

if(separateur=="Audio")
{
Audio*a=new Audio();

 f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>classif;

   a->setcode(cod);a->settitre(title);a->setauteur(aut);a->setannee(year);a->setnbEmprunts(nbem);a->setempruntable(e1);a->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);a->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);a->setgenre(gr);a->setclassification(classif);
 fe->set_docu(a);
}
if(separateur=="Video")
{//f.seekg(5, ios::cur);
    Video*vid=new Video();
    f>>cod>>title>>aut>>year>>nbem>>e1>>e2>>sa>>ray>>n>>ne>>duree>>mention;
vid->setcode(cod);vid->settitre(title);vid->setauteur(aut);vid->setannee(year);vid->setnbEmprunts(nbem);vid->setempruntable(e1);vid->setemprunte(e2);
lc.set_salle(sa);lc.set_rayon(ray);vid->setloc(lc);gr.set_nom(n);gr.set_nbEmprunts(ne);vid->setgenre(gr);vid->setdureefilm(duree);vid->setmentionlegale(mention);
 fe->set_docu(vid);}
v.push_back(*fe);
} }
}

else cout<<"erreur";
}
////////////////////////////////////////////////////////////////////////////////
void lirecategorie (vector<CategorieClient>&c,string const nomf)
{
ifstream f;
c.clear();
string nom;int nbEmpruntsMaxi;double cot , coefT , coefd ;bool codeRedactif;
string ch;
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{ if (ch=="Categorie")
 { CategorieClient * ca=new CategorieClient();
     f>>nom>>nbEmpruntsMaxi>>cot>>coefT>>coefd>>codeRedactif;
     ca->set_nomCat(nom);ca->set_nbEmpruntsMax(nbEmpruntsMaxi);ca->set_cotisation(cot);ca->set_coefTarif(coefT);
     ca->set_coefduree(coefd);ca->set_codedReductionactif(codeRedactif);

c.push_back(*ca);
}
}
}
else cout<<"erreur";
}
///////////////////////////////////////////////////////////////////////

void lirelocalisation (vector<Localisation>&l,string const nomf)
{
ifstream f;
l.clear();
string sa,ray;
string ch;
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{ if (ch=="Localisation")
 { Localisation* lo=new Localisation();
     f>>sa>>ray;
     lo->set_salle (sa);lo->set_rayon (ray);

l.push_back(*lo);
}
}
}
else cout<<"erreur";
}


/////////////////////////////////////////////////////
void liregenre (vector<Genre>&g,string const nomf)
{
ifstream f;
g.clear();
string name;int nbemprunts;
string ch;
f.open(nomf.c_str());
if(f)
{
while(f>>ch)
{ if (ch=="Genre")
 { Genre * ge=new Genre();
     f>>name>>nbemprunts;
     ge->set_nom (name);ge->set_nbEmprunts (nbemprunts);

g.push_back(*ge);
}
}
}
else cout<<"erreur";
}
