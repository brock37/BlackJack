#include "Joueur.h"

Joueur::Joueur()
{
    m_nombreJetons= 10;
    m_valeurPoint= 0;

}

Joueur::Joueur(unsigned int jetonDepart)
{
    m_valeurPoint=0;
    m_nombreJetons= jetonDepart;

}
Joueur::Joueur(unsigned int jetonDepart, sf::Vector2f pos)
{
    m_valeurPoint=0;
    m_nombreJetons= jetonDepart;

    m_position= pos;
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::piocher(Deck &deck)
{
    m_main.push_back(deck.tirerCarte());
}

void Joueur::afficherMain()
{
    for(unsigned int i(0) ; i < m_main.size(); i++)
        m_main[i].afficherCarte();
}

int Joueur::calculerValeurCarte()
{
    m_valeurPoint=0;

    for(unsigned int i(0) ; i < m_main.size(); i++)
        m_valeurPoint += m_main[i].getValeurPoint();



    return m_valeurPoint;
}

void Joueur::montreMain(sf::RenderTarget& target, sf::Texture* texture)
{
    for(unsigned int i(0); i < m_main.size() ; i++)
    {
        m_main[i].setTexture( texture);
        m_main[i].setTextureRect();
        m_main[i].setPosition(sf::Vector2f(m_position.x + (i* ESPACE_CARTE), m_position.y +(ESPACE_CARTE*i)));
        m_main[i].draw(target);

    }
}

void Joueur::cacherCarte(int carte)
{
    m_main[carte].retournerCarte();
}

void Joueur::lacherCarte()
{
    m_main.clear();
}

bool Joueur::annonceBlackJack()
{
    bool blackJack= false;
    if(m_main[0].getValeur() == UN)
    {
        if(m_main[1].getValeur() == ROI || m_main[1].getValeur() == DAME || m_main[1].getValeur() == VALET )
            blackJack= true;
    }
    if(m_main[1].getValeur() == UN)
    {
        if(m_main[0].getValeur() == ROI || m_main[0].getValeur() == DAME || m_main[0].getValeur() == VALET )
            blackJack= true;
    }
    return blackJack;
}
