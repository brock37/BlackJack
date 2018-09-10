#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED
class Joueur;
class Deck;
#include "joueur.h"
#include "carte.h"
#include "deck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>

#define NOMBRE_JETON_DEPART 100
#define HAUTEUR_CARTE 131
#define LARGEUR_CARTE 90
#define ESPACE_CARTE 20

enum Phase{MISE, TOUR_JOUEUR, TOUR_CROUPIER};

int prendreLamise(unsigned int& totalJetonjoueur , unsigned int miseJoueur);
std::string intToString(int val);
bool joueurVainqueur(int scoreJoueur,int scoreCroupier);
void tourCroupier( Joueur& croupier, Deck& deck, int valJoueur);




#endif // CONSTANTES_H_INCLUDED
