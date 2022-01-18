#include "date.h"

date::date (int j ,int m ,int a)
{      sep='/';
       jour=j;
       mois=m;
       annee=a;
}



date& date::adddate(int j)
{if (j==365) annee=annee+1;


else {
    if (mois==1 || mois==3 || mois==5 ||mois==7||mois==8||mois==10||mois==12 )
{if (jour+j>31 && mois!=12)
  {++mois;jour=jour+j-30;}
  else if (mois==12){++annee;++mois;jour=jour+j-30;}
  else jour=jour+j;
}
 else
 {if (mois==4 && jour+j>29) {++mois;jour=jour+j-28;}
 else if(jour+j>30){++mois;jour=jour+j-29;}
 else jour=jour+j;
}


}
return *this;
}
ostream& operator<<(ostream& s, date& d)
{s<<d.jour<<d.sep<<d.mois<<d.sep<<d.annee;
return s;
}

istream& operator>>(istream& e,date& d)
{
  e>>d.jour>>d.sep>>d.mois>>d.sep>>d.annee ;
  return e;
}

void date::getdateactuel()
{
    time_t current = time(0);
   tm *dte = localtime(&current);
   jour=dte->tm_mday;
   mois=1+dte->tm_mon;
   annee=1900+dte->tm_year;
   //date d(jour,mois,annee);
   //return d;
}
bool date::operator <(date d)
{bool t=false;
if (annee<d.annee) t=true;
if (d.annee==annee)
    {
       if (mois<d.mois) t=true ;
       else if(   d.mois==mois && jour<d.jour) t= true ;
     }
return t;
}



date::~date()
{
    //dtor
}
