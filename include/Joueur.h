#ifndef JOUEUR_H
#define JOUEUR_H


#include <vector>
#include <iostream>

class Carte;
class Deck;
#include "carte.h"
#include "deck.h"

class Joueur
{
    public:
        Joueur();
        Joueur(unsigned int jetonDepart);
        Joueur(unsigned int jetonDepart, sf::Vector2f pos);
        virtual ~Joueur();
        unsigned int& GetnombreJetons() { return m_nombreJetons; }
        void SetnombreJetons(unsigned int val) { m_nombreJetons += val; }
        unsigned int getValeurPoint(){ return m_valeurPoint;}
        void piocher(Deck &deck);
        void afficherMain();
        int calculerValeurCarte();
        void montreMain(sf::RenderTarget& target , sf::Texture* texture);
        void cacherCarte(int carte);
        void lacherCarte();
        bool annonceBlackJack();
    protected:
    private:
        unsigned int m_nombreJetons;
        std::vector<Carte> m_main;
        unsigned int m_valeurPoint;
        sf::Vector2f m_position;
};

#endif // JOUEUR_H
