#ifndef FICHIER_H
#define FICHIER_H
#include<fstream>
#include"Client.h"
#include"FicheEmprunt.h"
#include "Doc.h"
#include<vector>
#include "Audio.h"
#include "Video.h"
#include "Livre.h"




template<class c> void enregistrer(vector<c> v,string const nomf)

{ofstream f;
 f.open(nomf.c_str(),ios::trunc);

if(f){
 for(unsigned int i=0;i<v.size();++i)
    f<<v[i].affichefich()<<endl;
}
else cout<<"erreur";

f.close();
 }
void enregistrerdoc(vector<Doc*> v,string const nomf);


template<class c> void ajouter(c elt,string const nomf)
{ofstream f;
 f.open(nomf.c_str(),ios::app);
 if(f)
 {
    f<<elt.affichefich()<<endl;

}
else cout<<"erreur";
f.close();
}
void ajouterdoc(Doc* d,string const nomf);

void liredocument(vector<Doc*>&v,string const nomf);

void lireclient(vector<Client>&v,string const nomf);
void lirefiche(vector<FicheEmprunt>&v,string const nomf);
void lirelocalisation (vector<Localisation>&l,string const nomf);
void liregenre (vector<Genre>&g,string const nomf);


#endif
