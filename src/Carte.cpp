#include "Carte.h"

Carte::Carte()
{
    m_faceCacher= false;
    int color, val;
    color= couleurAleatoire();
    val= valeurAleatoire();

    switch(color)
    {
        case 0:
            m_couleur= PIQUE;
        break;
        case 1:
            m_couleur= TREFLE;
        break;
        case 2:
            m_couleur= CARREAU;
        break;
        case 3:
            m_couleur= COEUR;
        break;

    }

    switch(val)
    {
        case 0: m_valeur= UN; m_valeurPoint= 1; break;
        case 1: m_valeur= DEUX; m_valeurPoint= 2; break;
        case 2: m_valeur= TROIS;  m_valeurPoint= 3; break;
        case 3: m_valeur= QUATRE; m_valeurPoint= 4; break;
        case 4: m_valeur= CINQ; m_valeurPoint= 5; break;
        case 5: m_valeur= SIX; m_valeurPoint= 6; break;
        case 6: m_valeur= SEPT; m_valeurPoint= 7; break;
        case 7: m_valeur= HUIT; m_valeurPoint= 8; break;
        case 8: m_valeur= NEUF; m_valeurPoint= 9; break;
        case 9: m_valeur= DIX; m_valeurPoint= 10; break;
        case 10: m_valeur= VALET; m_valeurPoint= 10; break;
        case 11: m_valeur= DAME; m_valeurPoint= 10; break;
        case 12: m_valeur= ROI; m_valeurPoint= 10; break;
    }
}

Carte::Carte(Couleur color, Valeur val )
{
    m_faceCacher= false;
    m_couleur= color;
    m_valeur= val;

    switch(val)
    {
        case 0:  m_valeurPoint= 1; break;
        case 1:  m_valeurPoint= 2; break;
        case 2:   m_valeurPoint= 3; break;
        case 3:  m_valeurPoint= 4; break;
        case 4:  m_valeurPoint= 5; break;
        case 5:  m_valeurPoint= 6; break;
        case 6:  m_valeurPoint= 7; break;
        case 7:  m_valeurPoint= 8; break;
        case 8:  m_valeurPoint= 9; break;
        case 9:  m_valeurPoint= 10; break;
        case 10:  m_valeurPoint= 10; break;
        case 11:  m_valeurPoint= 10; break;
        case 12:  m_valeurPoint= 10; break;
    }


}

Carte::~Carte()
{

}

void Carte::setCouleur( Couleur color)
{
    m_couleur= color;
}

void Carte::setValeur (Valeur val)
{
    m_valeur= val;
}

int Carte::couleurAleatoire()
{
    return rand()%4;
}

int Carte::valeurAleatoire()
{
    return rand()%13;
}

void Carte::afficherCarte()
{
    std::cout << m_valeurPoint << " " ;
    switch(m_couleur)
    {
    case PIQUE:
        std::cout << "Pique" << " ";
        break;
    case TREFLE:
        std::cout << "Trefle" << " ";
        break;
    case CARREAU:
        std::cout << "Carreau" << " ";
        break;
    case COEUR:
        std::cout << "Coeur" << " ";
        break;

    }

    switch(m_valeur)
    {
        case UN: std::cout << "1" << std::endl; break;
        case DEUX: std::cout << "2" << std::endl; break;
        case TROIS: std::cout << "3" << std::endl; break;
        case QUATRE: std::cout << "4" << std::endl; break;
        case CINQ: std::cout << "5" << std::endl; break;
        case SIX: std::cout << "6" << std::endl; break;
        case SEPT: std::cout << "7" << std::endl; break;
        case HUIT: std::cout << "8" << std::endl; break;
        case NEUF: std::cout << "9" << std::endl; break;
        case DIX: std::cout << "10" << std::endl; break;
        case VALET: std::cout << "VALET" << std::endl; break;
        case DAME: std::cout << "DAME" << std::endl; break;
        case ROI: std::cout << "ROI" << std::endl; break;
    }


}

bool Carte::estEgal( Carte const& b) const
{
    if( m_valeur == b.m_valeur && m_couleur== b.m_couleur)
        return true;
    else
        return false;
}

void Carte::tirerNouvelleCarte()
{
    int color, val;
    color= couleurAleatoire();
    val= valeurAleatoire();

     switch(color)
    {
        case 0:
            m_couleur= PIQUE;
        break;
        case 1:
            m_couleur= TREFLE;
        break;
        case 2:
            m_couleur= CARREAU;
        break;
        case 3:
            m_couleur= COEUR;
        break;

    }

    switch(val)
    {
        case 0: m_valeur= UN; m_valeurPoint= 1; break;
        case 1: m_valeur= DEUX; m_valeurPoint= 2; break;
        case 2: m_valeur= TROIS;  m_valeurPoint= 3; break;
        case 3: m_valeur= QUATRE; m_valeurPoint= 4; break;
        case 4: m_valeur= CINQ; m_valeurPoint= 5; break;
        case 5: m_valeur= SIX; m_valeurPoint= 6; break;
        case 6: m_valeur= SEPT; m_valeurPoint= 7; break;
        case 7: m_valeur= HUIT; m_valeurPoint= 8; break;
        case 8: m_valeur= NEUF; m_valeurPoint= 9; break;
        case 9: m_valeur= DIX; m_valeurPoint= 10; break;
        case 10: m_valeur= VALET; m_valeurPoint= 10; break;
        case 11: m_valeur= DAME; m_valeurPoint= 10; break;
        case 12: m_valeur= ROI; m_valeurPoint= 10; break;
    }
}

void Carte::setTexture(sf::Texture *texture)
{
    m_texture= texture;
    m_sprite.setTexture( *texture);
}

void Carte::setTextureRect()
{
    int x,y;

    switch(m_valeur)
    {
        case UN: x=0; break;
        case DEUX: x= LARGEUR_CARTE * 1; break;
        case TROIS: x= LARGEUR_CARTE * 2; break;
        case QUATRE: x= LARGEUR_CARTE * 3; break;
        case CINQ: x= LARGEUR_CARTE * 4; break;
        case SIX: x= LARGEUR_CARTE * 5; break;
        case SEPT: x= LARGEUR_CARTE * 6; break;
        case HUIT: x= LARGEUR_CARTE * 7; break;
        case NEUF: x= LARGEUR_CARTE * 8; break;
        case DIX: x= LARGEUR_CARTE * 9; break;
        case VALET: x= LARGEUR_CARTE * 10; break;
        case DAME: x= LARGEUR_CARTE * 11; break;
        case ROI: x= LARGEUR_CARTE * 12; break;
    }

        switch(m_couleur)
    {
        case PIQUE:
            y= HAUTEUR_CARTE* 3;
        break;
        case TREFLE:
            y=0;
        break;
        case CARREAU:
            y= HAUTEUR_CARTE;
        break;
        case COEUR:
            y= HAUTEUR_CARTE* 2;
        break;

    }

    if( m_faceCacher)
    {
        x=LARGEUR_CARTE*2;
        y=HAUTEUR_CARTE*4;
    }

    m_sprite.setTextureRect(sf::IntRect(x,y,LARGEUR_CARTE, HAUTEUR_CARTE));

}

void Carte::setPosition(sf::Vector2f pos)
{
    m_sprite.setPosition(pos);
}


void Carte::draw(sf::RenderTarget& target)
{
    target.draw( m_sprite);
}

Carte& Carte::operator+=( Carte& b)
{

    m_valeurPoint= m_valeurPoint + b.m_valeurPoint;
    return *this;
}


Carte operator+(  Carte& a,  Carte& b)
{
    Carte copie(a);
    copie+= b;

    return copie;
}

bool operator==( Carte& a, Carte& b)
{

    return a.estEgal( b);
}
