#include <SFML/graphics.hpp>
#include "constantes.h"



using namespace std;

int main()
{
    srand (time(NULL));
    cout << "====Black Jack====" << endl;


    //----------------------Declaration des variables-------------------------
    unsigned int miseJoueur= 1;
    bool blackJack= false,gagne= false ;
    Joueur joueur1( NOMBRE_JETON_DEPART, sf::Vector2f(185, 330)), croupier(NOMBRE_JETON_DEPART, sf::Vector2f(185, 10));
    sf::RenderWindow window;
    sf::Font font;
    sf::Text texteValeurMise, texteNombreJetonJoueur, texteContinuer;
    sf::Texture textureJeton, textureTable, textureCarte;
    sf::Sprite spriteJeton, fondEcran;
    Phase phase= MISE;

    //----------------------Mise en place du fond d'ecran --------------------
    textureTable.loadFromFile( "table.png");
    fondEcran.setTexture( textureTable);


    //----------------------Creation du jeu de carte--------------------------
    Deck jeuxCarte;
    jeuxCarte.melanger();
    jeuxCarte.melanger();
    //jeuxCarte.afficherJeu();


    //---------------------Creation main des joueurs-----------------------------
    joueur1.piocher( jeuxCarte);
    croupier.piocher( jeuxCarte);
    joueur1.piocher( jeuxCarte);
    croupier.piocher( jeuxCarte);

    croupier.cacherCarte(1);

    //--------------------Creationde la fenetre --------------------------------
    window.create(sf::VideoMode(500,500), "BlackJack");

    //--------------------Initialisation des textes afficher-----------------------
    font.loadFromFile("Arial.ttf");

    texteValeurMise.setFont( font);
    texteValeurMise.setCharacterSize( 20);
    texteValeurMise.setPosition( 0, window.getSize().y -20);
    std::string chaineMise= "Mise: ";
    std::string chaineMiseAfficher= chaineMise + intToString(miseJoueur);
    texteValeurMise.setString( chaineMiseAfficher);

    texteNombreJetonJoueur.setFont(font);
    texteNombreJetonJoueur.setCharacterSize( 20);
    std::string chaineNbJetonJoueur= "Total Jeton: ";
    std::string chaineNbJetonJoueurAfficher= chaineNbJetonJoueur + intToString( joueur1.GetnombreJetons());
    texteNombreJetonJoueur.setString(chaineNbJetonJoueurAfficher);
    texteNombreJetonJoueur.setPosition( window.getSize().x /2, window.getSize().y - 20);

    texteContinuer.setFont( font);
    texteContinuer.setCharacterSize( 20);
    texteContinuer.setString("Appuyer sur entrer");
    texteContinuer.setPosition( window.getSize().x/2 - texteContinuer.getGlobalBounds().width /2, window.getSize().y /2);

    //--------------------Initialisation sprite et texture----------------------
    textureJeton.loadFromFile("Jeton.png");
    spriteJeton.setTexture( textureJeton);

    spriteJeton.setPosition(texteValeurMise.getPosition().x + texteValeurMise.getGlobalBounds().width , texteValeurMise.getPosition().y );

    textureCarte.loadFromFile("Cartes.png");

    //--------------------DebutPartie-------------------------------------------


    while( window.isOpen())
    {


            sf::Event event;
            while (window.pollEvent(event))
            {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Q)
                {
                    window.close();
                }
                /*condition si la mise n'est pas passer*/
                else if(event.key.code == sf::Keyboard::Up && phase == MISE)
                {
                    if( miseJoueur < joueur1.GetnombreJetons())
                        miseJoueur ++;
                }
                else if(event.key.code == sf::Keyboard::Down && phase == MISE)
                {
                    if( miseJoueur > 1)
                        miseJoueur --;
                }
                else if(event.key.code == sf::Keyboard::Return && phase == MISE)
                {
                    phase= TOUR_JOUEUR;

                    //mise a jour du nomre de jeton restant
                    prendreLamise( joueur1.GetnombreJetons(), miseJoueur);
                    chaineNbJetonJoueurAfficher= chaineNbJetonJoueur + intToString( joueur1.GetnombreJetons());
                    texteNombreJetonJoueur.setString(chaineNbJetonJoueurAfficher);

                    //On verifie si il y a black jack
                    blackJack= joueur1.annonceBlackJack();
                    if( blackJack)
                    {
                        gagne= true;
                        phase= TOUR_CROUPIER;
                    }
                }
                /*Conditions si la mise est passer le joueur peut demander des cartes*/
                else if(event.key.code == sf::Keyboard::Return && phase == TOUR_JOUEUR)
                {
                    phase= TOUR_CROUPIER;
                    //Le joueur valide sa main est le croupier commence a jouer
                    croupier.cacherCarte(1);//Retourne la carte face visible

                    //Il pioche si il le desire
                    do
                    {
                        tourCroupier(croupier, jeuxCarte, joueur1.calculerValeurCarte());
                    }while(joueur1.calculerValeurCarte() > croupier.calculerValeurCarte() );



                    //Comparaison des scores
                    int valjoueur, valcroupier;
                    valjoueur= joueur1.calculerValeurCarte();
                    valcroupier= croupier.calculerValeurCarte();
                    gagne= joueurVainqueur( valjoueur, valcroupier);


                    if(gagne)
                        joueur1.SetnombreJetons( miseJoueur*2);

                }
                else if(event.key.code == sf::Keyboard::Return && phase == TOUR_CROUPIER)
                {

                    //on initialise le deck ,les main des joueurs ainsi que les variables
                    phase= MISE;
                    miseJoueur= 1;
                    blackJack= false;
                    gagne= false;
                    jeuxCarte.reset();//On remet toutes les cartes dans le jeux
                    jeuxCarte.melanger();//on remelange

                    joueur1.lacherCarte();
                    croupier.lacherCarte();

                    joueur1.piocher( jeuxCarte);
                    croupier.piocher( jeuxCarte);
                    joueur1.piocher( jeuxCarte);
                    croupier.piocher( jeuxCarte);

                    croupier.cacherCarte(1);
                }
                //demande de carte
                else if(event.key.code == sf::Keyboard::C && phase == TOUR_JOUEUR )
                {
                    joueur1.piocher(jeuxCarte);
                    if(joueur1.calculerValeurCarte() > 21)//Si on depasse en piochant on arrete la partie
                    {
                        gagne=false;
                        phase= TOUR_CROUPIER;
                    }

                }
            }
        }

                        /*Mise a jour du nombre de jeton miser*/
            chaineMiseAfficher= chaineMise + intToString(miseJoueur);
            spriteJeton.setPosition(texteValeurMise.getPosition().x + texteValeurMise.getGlobalBounds().width, texteValeurMise.getPosition().y );
            texteValeurMise.setString( chaineMiseAfficher);

            chaineNbJetonJoueurAfficher= chaineNbJetonJoueur + intToString( joueur1.GetnombreJetons());
            texteNombreJetonJoueur.setString(chaineNbJetonJoueurAfficher);
            texteNombreJetonJoueur.setPosition( window.getSize().x /2, window.getSize().y - 20);

            window.clear();

            window.draw( fondEcran);
            if( phase == TOUR_JOUEUR || phase== TOUR_CROUPIER)
            {
                joueur1.montreMain( window, &textureCarte);
                croupier.montreMain( window, &textureCarte);
            }

            window.draw( texteValeurMise);
            window.draw( texteNombreJetonJoueur);
        /**< On change le texte central en fonction de la phase de jeu */
        //Si l'on doit miser
            if(phase == MISE)
            {
                texteContinuer.setString("Appuyer sur entrer \n      pour miser");
                window.draw( texteContinuer);
            }
            else if( phase == TOUR_JOUEUR)
            {
                texteContinuer.setString("Appuyer sur C pour une carte \n      entrer pour valider");
                texteContinuer.setPosition( window.getSize().x/2 - texteContinuer.getGlobalBounds().width /2, window.getSize().y /2);
                window.draw( texteContinuer);
            }
            //Si on a gagne
            if (phase == TOUR_CROUPIER && gagne)
            {
                texteContinuer.setString("Gagne\nEntrer pour rejouer\nQ pour quitter");
                texteContinuer.setPosition( window.getSize().x/2 - texteContinuer.getGlobalBounds().width /2, window.getSize().y /2);
                window.draw( texteContinuer);


            }
            //Sinon si on a perdu
            else if (phase == TOUR_CROUPIER&& !gagne)
            {
                texteContinuer.setString("Perdu\nEntrer pour rejouer\nQ pour quitter");
                texteContinuer.setPosition( window.getSize().x/2 - texteContinuer.getGlobalBounds().width /2, window.getSize().y /2);
                window.draw( texteContinuer);
            }

            window.draw( spriteJeton);

            window.display();



    }


    return 0;
}

int prendreLamise(unsigned int& totalJetonjoueur, unsigned int miseJoueur)
{

    if( miseJoueur == 0)
    {
        cout << "Vous devez miser au moins 1" << endl;
        miseJoueur= 1;
    }
    else if( miseJoueur > totalJetonjoueur)
    {
        cout << "Vous n'avez pas asse de jetons" << endl  ;
        miseJoueur = totalJetonjoueur;
        cout << "Vous misez donc le maximum " << miseJoueur << " Jetons" << endl;
    }
    else
    {
        cout << "Vous avez miser " << miseJoueur << " jetons" << endl;

    }
    totalJetonjoueur -= miseJoueur;
    return miseJoueur;
}

std::string intToString(int val)
{
    // créer un flux de sortie
    std::ostringstream oss;
    // écrire un nombre dans le flux
    oss << val;
    // récupérer une chaîne de caractères
    return oss.str();
}

bool joueurVainqueur(int scoreJoueur,int scoreCroupier)
{
    bool gagne= false;

    if( scoreJoueur < scoreCroupier)
    {
        gagne= false;
    }
    else if(scoreJoueur >= scoreCroupier)
    {
        gagne= true;
    }
    if( scoreCroupier > 21)
        gagne= true;


    return gagne;
}

void tourCroupier( Joueur& croupier, Deck& deck, int valJoueur)
{
    int valCroupier= croupier.calculerValeurCarte();

    if (valCroupier <= valJoueur)
    {
        croupier.piocher( deck);
    }




}


