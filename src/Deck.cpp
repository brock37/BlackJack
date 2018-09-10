#include "Deck.h"

Deck::Deck()
{
    m_tasCarte.clear();
    m_tasCarte.push_back(Carte(PIQUE, UN));
    m_tasCarte.push_back(Carte(PIQUE, DEUX));
    m_tasCarte.push_back(Carte(PIQUE, TROIS));
    m_tasCarte.push_back(Carte(PIQUE, QUATRE));
    m_tasCarte.push_back(Carte(PIQUE, CINQ));
    m_tasCarte.push_back(Carte(PIQUE, SIX));
    m_tasCarte.push_back(Carte(PIQUE, SEPT));
    m_tasCarte.push_back(Carte(PIQUE, HUIT));
    m_tasCarte.push_back(Carte(PIQUE, NEUF));
    m_tasCarte.push_back(Carte(PIQUE, DIX));
    m_tasCarte.push_back(Carte(PIQUE, VALET));
    m_tasCarte.push_back(Carte(PIQUE, DAME));
    m_tasCarte.push_back(Carte(PIQUE, ROI));

    m_tasCarte.push_back(Carte(TREFLE, UN));
    m_tasCarte.push_back(Carte(TREFLE, DEUX));
    m_tasCarte.push_back(Carte(TREFLE, TROIS));
    m_tasCarte.push_back(Carte(TREFLE, QUATRE));
    m_tasCarte.push_back(Carte(TREFLE, CINQ));
    m_tasCarte.push_back(Carte(TREFLE, SIX));
    m_tasCarte.push_back(Carte(TREFLE, SEPT));
    m_tasCarte.push_back(Carte(TREFLE, HUIT));
    m_tasCarte.push_back(Carte(TREFLE, NEUF));
    m_tasCarte.push_back(Carte(TREFLE, DIX));
    m_tasCarte.push_back(Carte(TREFLE, VALET));
    m_tasCarte.push_back(Carte(TREFLE, DAME));
    m_tasCarte.push_back(Carte(TREFLE, ROI));

    m_tasCarte.push_back(Carte(COEUR, UN));
    m_tasCarte.push_back(Carte(COEUR, DEUX));
    m_tasCarte.push_back(Carte(COEUR, TROIS));
    m_tasCarte.push_back(Carte(COEUR, QUATRE));
    m_tasCarte.push_back(Carte(COEUR, CINQ));
    m_tasCarte.push_back(Carte(COEUR, SIX));
    m_tasCarte.push_back(Carte(COEUR, SEPT));
    m_tasCarte.push_back(Carte(COEUR, HUIT));
    m_tasCarte.push_back(Carte(COEUR, NEUF));
    m_tasCarte.push_back(Carte(COEUR, DIX));
    m_tasCarte.push_back(Carte(COEUR, VALET));
    m_tasCarte.push_back(Carte(COEUR, DAME));
    m_tasCarte.push_back(Carte(COEUR, ROI));

    m_tasCarte.push_back(Carte(CARREAU, UN));
    m_tasCarte.push_back(Carte(CARREAU, DEUX));
    m_tasCarte.push_back(Carte(CARREAU, TROIS));
    m_tasCarte.push_back(Carte(CARREAU, QUATRE));
    m_tasCarte.push_back(Carte(CARREAU, CINQ));
    m_tasCarte.push_back(Carte(CARREAU, SIX));
    m_tasCarte.push_back(Carte(CARREAU, SEPT));
    m_tasCarte.push_back(Carte(CARREAU, HUIT));
    m_tasCarte.push_back(Carte(CARREAU, NEUF));
    m_tasCarte.push_back(Carte(CARREAU, DIX));
    m_tasCarte.push_back(Carte(CARREAU, VALET));
    m_tasCarte.push_back(Carte(CARREAU, DAME));
    m_tasCarte.push_back(Carte(CARREAU, ROI));
}

Deck::~Deck()
{
    //dtor
}

void Deck::afficherJeu()
{
    for(unsigned int i(0); i < m_tasCarte.size(); i++)
        m_tasCarte[i].afficherCarte();
}

void Deck::melanger()
{
    std::random_shuffle(m_tasCarte.begin(), m_tasCarte.end());
}

Carte Deck::tirerCarte()
{
    Carte carteTirer( m_tasCarte[0]);
    m_tasCarte.erase( m_tasCarte.begin());
    return carteTirer;
}

void Deck::reset()//Remet le jeux a zero
{
    m_tasCarte.clear();
    m_tasCarte.push_back(Carte(PIQUE, UN));
    m_tasCarte.push_back(Carte(PIQUE, DEUX));
    m_tasCarte.push_back(Carte(PIQUE, TROIS));
    m_tasCarte.push_back(Carte(PIQUE, QUATRE));
    m_tasCarte.push_back(Carte(PIQUE, CINQ));
    m_tasCarte.push_back(Carte(PIQUE, SIX));
    m_tasCarte.push_back(Carte(PIQUE, SEPT));
    m_tasCarte.push_back(Carte(PIQUE, HUIT));
    m_tasCarte.push_back(Carte(PIQUE, NEUF));
    m_tasCarte.push_back(Carte(PIQUE, DIX));
    m_tasCarte.push_back(Carte(PIQUE, VALET));
    m_tasCarte.push_back(Carte(PIQUE, DAME));
    m_tasCarte.push_back(Carte(PIQUE, ROI));

    m_tasCarte.push_back(Carte(TREFLE, UN));
    m_tasCarte.push_back(Carte(TREFLE, DEUX));
    m_tasCarte.push_back(Carte(TREFLE, TROIS));
    m_tasCarte.push_back(Carte(TREFLE, QUATRE));
    m_tasCarte.push_back(Carte(TREFLE, CINQ));
    m_tasCarte.push_back(Carte(TREFLE, SIX));
    m_tasCarte.push_back(Carte(TREFLE, SEPT));
    m_tasCarte.push_back(Carte(TREFLE, HUIT));
    m_tasCarte.push_back(Carte(TREFLE, NEUF));
    m_tasCarte.push_back(Carte(TREFLE, DIX));
    m_tasCarte.push_back(Carte(TREFLE, VALET));
    m_tasCarte.push_back(Carte(TREFLE, DAME));
    m_tasCarte.push_back(Carte(TREFLE, ROI));

    m_tasCarte.push_back(Carte(COEUR, UN));
    m_tasCarte.push_back(Carte(COEUR, DEUX));
    m_tasCarte.push_back(Carte(COEUR, TROIS));
    m_tasCarte.push_back(Carte(COEUR, QUATRE));
    m_tasCarte.push_back(Carte(COEUR, CINQ));
    m_tasCarte.push_back(Carte(COEUR, SIX));
    m_tasCarte.push_back(Carte(COEUR, SEPT));
    m_tasCarte.push_back(Carte(COEUR, HUIT));
    m_tasCarte.push_back(Carte(COEUR, NEUF));
    m_tasCarte.push_back(Carte(COEUR, DIX));
    m_tasCarte.push_back(Carte(COEUR, VALET));
    m_tasCarte.push_back(Carte(COEUR, DAME));
    m_tasCarte.push_back(Carte(COEUR, ROI));

    m_tasCarte.push_back(Carte(CARREAU, UN));
    m_tasCarte.push_back(Carte(CARREAU, DEUX));
    m_tasCarte.push_back(Carte(CARREAU, TROIS));
    m_tasCarte.push_back(Carte(CARREAU, QUATRE));
    m_tasCarte.push_back(Carte(CARREAU, CINQ));
    m_tasCarte.push_back(Carte(CARREAU, SIX));
    m_tasCarte.push_back(Carte(CARREAU, SEPT));
    m_tasCarte.push_back(Carte(CARREAU, HUIT));
    m_tasCarte.push_back(Carte(CARREAU, NEUF));
    m_tasCarte.push_back(Carte(CARREAU, DIX));
    m_tasCarte.push_back(Carte(CARREAU, VALET));
    m_tasCarte.push_back(Carte(CARREAU, DAME));
    m_tasCarte.push_back(Carte(CARREAU, ROI));
}
