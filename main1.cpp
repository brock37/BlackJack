#include <SFML/graphics.hpp>
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
    bool blackJack= false;
    bool donnerDesCartes= true;
    Joueur joueur1( NOMBRE_JETON_DEPART), croupier(NOMBRE_JETON_DEPART);

    //----------------------Creation du jeu de carte--------------------------
    Deck jeuxCarte;
    jeuxCarte.melanger();
    jeuxCarte.melanger();
    //jeuxCarte.afficherJeu();

    //----------------------Prise des mises------------------------------------
    cout << "Vous avez " << joueur1.GetnombreJetons() << " Jetons" << endl;
    miseJoueur= prendreLamise(joueur1.GetnombreJetons() );


    cout << "Vous avez " << joueur1.GetnombreJetons() << " Jetons" << endl;

    //---------------------Creation main des joueurs-----------------------------
    joueur1.piocher( jeuxCarte);
    croupier.piocher( jeuxCarte);
    joueur1.piocher( jeuxCarte);
    croupier.piocher(jeuxCarte);

    joueur1.calculerValeurCarte(blackJack);
    croupier.calculerValeurCarte(blackJack);
    //--------------------DebutPartie-------------------------------------------
    joueur1.afficherMain();
    cout << joueur1.getValeurPoint() << endl;

    croupier.afficherMain();
    cout << croupier.getValeurPoint() << endl;




        //pioche une carte ou non
        do
        {
            cout << "voulez-vous une carte supplementaire? ";
            cin >> choix;
            if(choix == 1)
            {
                joueur1.piocher( jeuxCarte);
                joueur1.afficherMain();
                joueur1.calculerValeurCarte( blackJack);
                cout << joueur1.getValeurPoint() << endl;
            }
            else
            {
                donnerDesCartes= false;
            }

            if( joueur1.getValeurPoint() > 21)
            {
                donnerDesCartes= false;
            }

        }while( donnerDesCartes && !blackJack);

        //---------------------Fin de partie-----------------------------------------
        if(croupier.getValeurPoint() > joueur1.getValeurPoint() || joueur1.getValeurPoint() > 21)
        {
            cout << "La banque gagne" << endl;
        }
        else if(croupier.getValeurPoint() < joueur1.getValeurPoint() ||croupier.getValeurPoint() > 21)
        {
            cout << "Vous avez gagner" << endl;
        }
        else
        {
            cout << "Egaliter" << endl;
        }




    return 0;
}

int prendreLamise(unsigned int& totalJetonjoueur)
{
    unsigned int miseJoueur=0;

    do
    {
        cout << "Combien misez-vous? " ;
        cin >> miseJoueur;
        if( miseJoueur == 0)
        {
            cout << "Vous devez miser au moins 1" << endl;
        }
    }while( miseJoueur==0);


    if( miseJoueur > totalJetonjoueur)
    {
        cout << "Vous n'avez pas asse de jetons" << endl  ;
        miseJoueur = totalJetonjoueur;
        totalJetonjoueur= 0;
        cout << "Vous misez donc le maximum " << miseJoueur << " Jetons" << endl;
    }
    else
    {
        cout << "Vous avez miser " << miseJoueur << " jetons" << endl;
        totalJetonjoueur -= miseJoueur;
    }

    return miseJoueur;
}


