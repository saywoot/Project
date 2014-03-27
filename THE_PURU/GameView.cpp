#include "GameView.h"
#include "GameModel.h"
#include "Const.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

/************************************************************
/Nom: GameView                                              *
/************************************************************
/Type: Constructeur                                         *
/***********************************************************/
GameView::GameView(){

}
/************************************************************
/Nom: ~GameView                                             *
/************************************************************
/Type: Desstructeur                                         *
/***********************************************************/
GameView::~GameView()
{

}
/************************************************************
/Nom: setModel                                              *
/************************************************************
/Type: Constructeur                                         *
/************************************************************
/Paramètres: model de type GameModel*                       *
*************************************************************
/Rôle: Affecte un model à un autre model                    *
/***********************************************************/
void GameView::setModel(GameModel *model)
{
    m_model = model;
}
/************************************************************
/Nom: affiche                                               *
/************************************************************
/Type: void                                                 *
/************************************************************
/Rôle: Fonction qui affiche la matrice à l'écran et         *
/      l'affichage des scores                               *
/***********************************************************/
void GameView::affiche() const
{
    Case ***matrice = m_model->getMatrice();

    /* Affichage */
    for(int i=0; i<18; i++){
        cout << ("\t\t\t\t|---");
        for(int k=0; k<17; k++)
            cout << "|---";
        cout <<"|" << endl << "\t\t\t\t";
        for(int j=0; j<18; j++){
            if(m_model->getPlayer().get_x() == j && m_model->getPlayer().get_y() == i)
            {
                cout << "|$$$";
            }
            else if(matrice[i][j]->getObj() == "$$$" || matrice[i][j]->getObj() == "@@@")
                cout << "|" << matrice[i][j]->getObj();
            else if(matrice[i][j]->getObj() == "-1-" || matrice[i][j]->getObj() == "-2-" || matrice[i][j]->getObj() == "-3-" ||
                    matrice[i][j]->getObj() == "-4-" || matrice[i][j]->getObj() == "-5-" || matrice[i][j]->getObj() == "-6-")
                cout << "|" << matrice[i][j]->getObj();
            else
                cout << "| " << matrice[i][j]->getObj() <<" ";
        }
        cout << "|" <<endl ;
    }
    cout << "\t\t\t\t|---";
    for(int k=0; k<17; k++)
        cout << "|---";
    cout << "|" <<endl ;
    cout << endl;

    cout <<  m_model->getScore().toString() << m_model->getLvl().toString() << "\t\t\t\t" << m_model->getPlayer().toString() << endl;
}
/************************************************************
/Nom: answer_move                                           *
/************************************************************
/Type: void                                                 *
/************************************************************
/Paramètres: model de type GameModel*                       *
*************************************************************
/Rôle: Demande la direction dans laquelle l'utilisateur veut*
/      aller et redemande tant que l'entrée n'ets pas valide*
/***********************************************************/
void GameView::answer_move(GameModel *model) {
    string answer;
    do{
        cout << "\n\nAbandonner : 1" << endl;
        cout << "Dans quelle direction voulez-vous déplacer le mineur ? (N / NE / E / SE / S / SO / O / NO) : " << endl;
        cin >> answer;
    }while(!model->check_answer(answer));
    model->set_answer_move(answer);
}
/************************************************************
/Nom: presentation                                          *
/************************************************************
/Type: void                                                 *
/************************************************************
/Rôle: Affiche l'en tête de début de jeu                    *
/***********************************************************/
void GameView::presentation() const
{
    cout <<"  ___   _     _   ___   _     _       ___   _     _   ___   _     _      ___    _    ____      ____     _____   ___"                           << endl;
    cout <<" /   \\ | |   | | /   \\ | |   | |     /   \\ | |   | | /   \\ | |   | |    |   \\  | |  / __ \\    / __ \\   |  ___| /   \\ "                   << endl;
    cout <<"|  _  \\| |   | ||  _  \\| |   | |    |  _  \\| |   | ||  _  \\| |   | |    | |\\ \\ | | / /  \\_\\  / /  \\_\\  | |    |  _  \\"               << endl;
    cout <<"| |_| /| |   | || |_| /| |   | | __ | |_| /| |   | || |_| /| |   | | __ | | | || || |    __ | |    __  | |__  | |_| / "                         << endl;
    cout <<"|  __/ | |   | ||  __/ | |   | ||__||  __/ | |   | ||  __/ | |   | ||__|| | | || || |   | _|| |   | _| |  __| |  __/     "                        << endl;
    cout <<"| |    | |   | ||   \\  | |   | |    | |    | |   | ||   \\  | |   | |    | | | || || |   | | | |   | |  | |    |   \\"                       << endl;
    cout <<"| |    | \\___/ || |\\ \\ | \\___/ |    | |    | \\___/ || |\\ \\ | \\___/ |    | |/ / | | \\ \\__/ |  \\ \\__/ |  | |___ | |\\ \\"             << endl;
    cout <<"|_|     \\_____/ |_| \\_\\ \\_____/     |_|     \\_____/ |_| \\_\\ \\_____/     |___/  |_|  \\____/    \\____/   |_____||_| \\_\\"                << endl;
    cout << endl;
    cout << endl;
    cout << "Voulez-vous jouer ou quitter ? \n" << endl;
    cout  << "Jouer: 0" << "\tQuitter: 1 " << "\tMeilleurScores: 2" << endl;
}
/************************************************************
/Nom: rejouer                                               *
/************************************************************
/Type: void                                                 *
/************************************************************
/Rôle: Affiche la question                                  *
/***********************************************************/
void GameView::rejouer() const
{
    cout << "Vous avez perdu ou décider d'abandonner" << endl;
    cout << " Voulez rejouer ? " << endl;
    cout << " Quitter: 1 " << "\t" << "Rejouer: 0" << endl;
}
/************************************************************
/Nom: affichageScore                                        *
/************************************************************
/Type: void                                                 *
/************************************************************
/Rôle: Affiche les scores(ouverture et fermeture de fichier)*
/***********************************************************/
void GameView::affichageScore() const
{
    fstream f;
    f.open("scores.txt", ios::in); // ouverture du fichier en ecriture ficNb
    if( f.fail() )
    {// Si probleme afficher une erreur
        cerr << "ouverture en lecture impossible" << endl;
        f.close();
    }
    string phrase;
    f >> phrase;
    while(!f.eof()){
        cout << phrase << endl;
        f >> phrase;
    }
    cout << endl;

    f.close(); // fermeture du fichier
}
/************************************************************
/Nom: retourMenu                                            *
/************************************************************
/Type: void                                                 *
/************************************************************
/Rôle: Affiche une question et un choix menu                *
/***********************************************************/
void GameView::retourMenu() const
{
    cout << "\n\nVoulez-vous quitter ou jouer ?" << endl;
    cout  << "Jouer: 0" << "\tQuitter: 1 " << endl;
}




