#include <iostream>
#include "constantes.h"


using namespace std;

int main()
{
    srand (time(NULL));
    cout << "====Black Jack====" << endl;

    //----------------------Declaration des variables-------------------------
    int JetonJoueur= NOMBRE_JETON_DEPART;
    int miseJoueur= 0;
    int choix(0);

    //----------------------Creation du jeu de carte--------------------------
    Deck jeuxCarte;
    jeuxCarte.melanger();
    jeuxCarte.melanger();
    //jeuxCarte.afficherJeu();

    //----------------------Prise des mises------------------------------------
    cout << "Vous avez " << JetonJoueur << " Jetons" << endl;
    miseJoueur= prendreLamise( &JetonJoueur);


    cout << "Vous avez " << JetonJoueur << " Jetons" << endl;

    //---------------------Creation main du joueur-----------------------------
    vector<Carte>mainJoueur;
    /*mainJoueur.push_back( jeuxCarte.tirerCarte());
    mainJoueur.push_back( jeuxCarte.tirerCarte());*/
    mainJoueur.push_back( Carte( PIQUE, VALET));
    mainJoueur.push_back( Carte( PIQUE, UN));

    for(unsigned int i(0); i < mainJoueur.size(); i++)
        mainJoueur[i].afficherCarte();


    //Si on a un as et une buche(figure)
    if( mainJoueur[0].getValeur() == UN )
    {
        if(mainJoueur[1].getValeur() == ROI || mainJoueur[1].getValeur() == DAME || mainJoueur[1].getValeur() == VALET || mainJoueur[1].getValeur() == DIX)
        {
            cout << "Black Jack!!!"<< endl;
        }
    }
    else if(mainJoueur[1].getValeur() == UN)
    {
        if(mainJoueur[0].getValeur() == ROI || mainJoueur[0].getValeur() == DAME || mainJoueur[0].getValeur() == VALET || mainJoueur[0].getValeur() == DIX)
        {
            cout << "Black Jack!!!"<< endl;
        }
    }





    do//Boucle demande de carte
    {
        cout << "Voulez-vous une carte supplementaire?" << endl;
        cout << "1: Oui" << endl << "2:Non" << endl;
        cin >> choix;

        if(choix == 1)
        {
            //Tirer une nouvelle carte et additionner les valeur
            mainJoueur.push_back( jeuxCarte.tirerCarte());
            for(unsigned int i(0); i < mainJoueur.size(); i++)
                mainJoueur[i].afficherCarte();

        }
        else
        {
            //Onregarde la main du croupier et onregarde qui est le plus pres de 21
        }
    }while( choix == 1);

    return 0;
}

int prendreLamise(int* totalJetonjoueur)
{
    int miseJoueur=0;

    do
    {
        cout << "Combien misez-vous? " ;
        cin >> miseJoueur;
        if( miseJoueur == 0)
        {
            cout << "Vous devez miser au moins 1" << endl;
        }
    }while( miseJoueur==0);


    if( miseJoueur > *totalJetonjoueur)
    {
        cout << "Vous n'avez pas asse de jetons" << endl  ;
        miseJoueur = *totalJetonjoueur;
        *totalJetonjoueur= 0;
        cout << "Vous misez donc le maximum " << miseJoueur << " Jetons" << endl;
    }
    else
    {
        cout << "Vous avez miser " << miseJoueur << " jetons" << endl;
        *totalJetonjoueur -= miseJoueur;
    }

    return miseJoueur;
}


