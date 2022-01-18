#include "FicheEmprunt.h"
#include"Client.h"

FicheEmprunt::FicheEmprunt(bool depasse,double tar)
{
       depassee=depasse;
       tarif=tar;
}



void FicheEmprunt::calculer_le_tarif ()
{
tarif=cli->getcategorie().get_coefTarif()*docu->tarifEmprunt();
}
int FicheEmprunt:: verifier_les_emprunts ()
{
     date d; d.getdateactuel() ;
     if (d < dateLimite)
     {
            cout<<" La date limite n'est pas aujourd'hui ";
        return 0;
     }

     else if (dateLimite<d)

        {
       cout <<" La date limite est atteinte "<<endl;
       return 1; }

     else {
       cout <<" La date limite est aujourd'hui "<<endl;
       return 2; }
}
// **** get
date FicheEmprunt:: get_dateEmprunt() { return dateEmprunt ;}
date FicheEmprunt:: get_dateLimite() {return dateLimite ; }
date FicheEmprunt:: get_dateRappel()  {return dateRappel ; }
bool FicheEmprunt:: get_depassee(){return depassee ;  }
double FicheEmprunt:: get_tarif() {return tarif ; }
Client* FicheEmprunt::get_cli() {return cli ;}
Doc* FicheEmprunt:: get_docu() {return docu ; }

// ***** set
void FicheEmprunt::set_dateEmprunt()
{
//cout<<"Donner la date d emprunt: ";
//cin>>d;
       dateEmprunt.getdateactuel();
}
void FicheEmprunt::set_dateLimite ()
{date d=dateEmprunt;
       dateLimite=d.adddate(docu->dureeEmprunt());

}
void FicheEmprunt::set_dateRappel ()
{date d=dateLimite;
d.setjour(dateLimite.getjour()-1);
if (d.getjour()==0) {
   if (d.getmois()==1 || d.getmois()==3 || d.getmois()==5 ||d.getmois()==7||d.getmois()==8||d.getmois()==10||d.getmois()==12 )
    {if (d.getmois()==1) {d.setmois(12);d.setjour(31);d.setannee(d.getannee()-1);}
     else {d.setjour(30);d.setmois(d.getmois()-1);}
    }
    else {d.setjour(31);d.setmois(d.getmois()-1);}
}
 dateRappel=d;
}
void FicheEmprunt::setdateEmprunt(date d){dateEmprunt=d;}
void FicheEmprunt::setdateLimite(date d){dateLimite=d;}
void FicheEmprunt::setdateRappel(date d){dateRappel=d;}
void FicheEmprunt::set_depassee(bool depace) {depassee=depace;}
void FicheEmprunt::set_tarif(double  trf) {tarif=trf;}
void FicheEmprunt::set_cli(Client*cl) {cli=cl;}
void FicheEmprunt::set_docu(Doc*d) {docu=d;}


string FicheEmprunt::affiche()
{stringstream aff;

if (depassee)
    aff<<"********************* FICHE EMPEUNT *********************\n"<<"Type du document: "<< docu->affiche()<<"\n"<<cli->affiche()<<"\nDate Emprunt:  "<<dateEmprunt<<"\nDate limite:  "<<dateLimite<<"\nDate rappel: "<<dateRappel<<"\nLa date limite est depass"<<char (130)<<"e. "<<endl;
else
    aff<<"********************* FICHE EMPRUNT *********************\n"<<"Type du document: "<< docu->affiche()<<"\n"<<cli->affiche()<<"\nDate Emprunt:  "<<dateEmprunt<<"\nDate limite:  "<<dateLimite<<"\nDate rappel: "<<dateRappel<<"\nLa date limite n'est pas encore atteinte. "<< endl;


return aff.str();
}



string FicheEmprunt::affichefich()
{stringstream aff;

aff<<"Fiche "<<dateEmprunt<<" "<<dateLimite<<" "<<dateRappel<<" "<<depassee<<" "<<tarif<<" "<<cli->affichefich()<<" "<<docu->affichefich();
return aff.str();
}


