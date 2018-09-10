#ifndef CARTE_H
#define CARTE_H

#include <SFML/graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "constantes.h"



enum Couleur {PIQUE, TREFLE, CARREAU, COEUR};
enum Valeur {UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI};


class Carte
{
    public:
        Carte();
        Carte(Couleur color, Valeur val );
        virtual ~Carte();
        void setCouleur( Couleur color);
        void setValeur (Valeur val);
        int couleurAleatoire();
        int valeurAleatoire();
        void afficherCarte();
        Couleur getCouleur(){return m_couleur;}
        Valeur getValeur(){return m_valeur;}
        int getValeurPoint(){return m_valeurPoint;}
        bool estEgal( Carte const& a)const;
        void tirerNouvelleCarte();
        void setTexture( sf::Texture *texture);
        void setTextureRect();
        void setPosition(sf::Vector2f pos);
        void draw(sf::RenderTarget& target);
        void retournerCarte(){ m_faceCacher = !m_faceCacher;}

        Carte& operator+=( Carte& b);


    protected:
    private:
        Couleur m_couleur;
        Valeur m_valeur;
        int m_valeurPoint;
        sf::Texture* m_texture;
        sf::Sprite m_sprite;
        bool m_faceCacher;

};

Carte operator+(  Carte& a,  Carte& b);
bool operator==( Carte& a, Carte& b);


#endif // CARTE_H
