#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std ;


class date
{
int jour;
int mois;
int annee;
char sep;
public :
date (int j=0,int m=0,int a=0);
date& adddate(int j);
friend ostream& operator<<(ostream& s,date& d);
friend istream& operator>>(istream& e,date& d);
void getdateactuel();
bool operator <(date d);

int getjour() { return jour ;}
int getmois() { return mois ;}
int getannee() { return annee ;}
void setjour (int j) { jour=j ;}
void setmois (int m) { mois=m ;}
void setannee (int a) { annee=a ;}



~date ();

};

#endif // DATE_H
