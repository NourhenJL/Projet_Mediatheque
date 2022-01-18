#ifndef GENRE_H
#define GENRE_H

#include <iostream>
#include <string>
#include <vector>
#include<sstream>

using namespace std ;



class Genre
{
string nom ;
int nbEmprunts;

public :
Genre (string name ="");
~Genre ()
{  }
bool operator<(Genre&g);
bool operator==(Genre g);
string affiche();
  string affichefich();
// **** get ****
string get_nom() ;
int get_nbEmprunts() ;

// ***** set ****
void set_nom(string n) ;
void set_nbEmprunts(int nbE) ;



};

#endif // GENRE_H
