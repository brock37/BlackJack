#ifndef DECK_H
#define DECK_H
//#include "Carte.h"
#include <vector>
#include <algorithm>

class Carte;
#include "Carte.h"

class Deck
{
    public:
        Deck();
        virtual ~Deck();
        void afficherJeu();
        void melanger();
        Carte tirerCarte();
        void reset();
    protected:
    private:
         std::vector<Carte> m_tasCarte;
};

#endif // DECK_H
