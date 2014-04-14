#include "GameView.h"
#include "GameModel.h"
#include "Const.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

/************************************************************
 * Nom: GameView                                            *
 ************************************************************
 * Type: Constructeur                                       *
 ************************************************************/
GameView::GameView(){

}
/************************************************************
 * Nom: ~GameView                                           *
 ************************************************************
 * Type: Desstructeur                                       *
 ************************************************************/
GameView::~GameView()
{

}
/************************************************************
 * Nom: setModel                                            *
 ************************************************************
 * Type: Constructeur                                       *
 ************************************************************
 * Paramètres: model de type GameModel                      *
 ************************************************************
 * Rôle: Affecte un model à un autre model                  *
 ************************************************************/
void GameView::setModel(GameModel *model)
{
    m_model = model;
}
string GameView::afficheBonus() const
{
    ostringstream out;
    out << "Score Bonus :" << m_model->getLvl().get_score_bonus() << "\t\t\t\tBonus Temps: " << m_model->getLvl().get_b_temps() << "\t\t\t\tBonus Vie: " << m_model->getLvl().get_b_vie()  << "\nLevel : " << m_model->getLvl().getLevel();
    string s = out.str();
    return s;
}
string GameView::afficheScore() const
{
    ostringstream out;
     out<< "Le score déplacement: " << m_model->getScore().getDeplacement() << "\t\t\tLe score cible: " << m_model->getScore().getCible() << "\t\t\tLe score total: " << m_model->getScore().getScoreTotal() << endl;
    string s = out.str();
    return s;
}
string GameView::viePlayer() const
{
    ostringstream out;
    out<< "\tVie du joueur: " << m_model->getPlayer().getVie();
    
    string s= out.str();
    return s;
}
/************************************************************
 * Nom: affiche                                             *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle: Fonction qui affiche la matrice à l'écran et       *
 *     l'affichage des scores                               *
 ************************************************************/
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
             if(dynamic_cast<Bomb*>(matrice[i][j]))
                cout << "|" << "@@@";
            else if(m_model->getPlayer().get_x() == j && m_model->getPlayer().get_y() == i)
                cout << "|$$$";
            else if(dynamic_cast<BonusCase*>(matrice[i][j]))
                cout << "|" << matrice[i][j]->getObj();
            else
                cout << "| " << matrice[i][j]->getObj() << " ";
        }
        cout << "|" <<endl ;
    }
    cout << "\t\t\t\t|---";
    for(int k=0; k<17; k++)
        cout << "|---";
    cout << "|" <<endl ;
    cout << endl;
    
    cout <<  afficheScore() << afficheBonus() << "\t\t\t\t" << viePlayer() << endl;
}
/**************************************************************
 * Nom: answer_move                                           *
 **************************************************************
 * Type: void                                                 *
 **************************************************************
 * Paramètres: model de type GameModel                        *
 **************************************************************
 * Rôle: Demande la direction dans laquelle l'utilisateur veut*
 *     aller et redemande tant que l'entrée n'ets pas valide  *
 **************************************************************/
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
 * Nom: presentation                                        *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle: Affiche l'en tête de début de jeu                  *
 ************************************************************/
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
 * Nom: rejouer                                             *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle: Affiche la question                                *
 ************************************************************/
 void GameView::rejouer()
{
    cout << "Vous avez perdu ou décider d'abandonner" << endl;
    cout << " Voulez rejouer ? " << endl;
    cout << " Quitter: 1 " << "\t" << "Rejouer: 0" << endl;
}
/**************************************************************
 * Nom: affichageScore                                        *
 **************************************************************
 * Type: void                                                 *
 **************************************************************
 * Rôle: Affiche les scores(ouverture et fermeture de fichier)*
 **************************************************************/
void GameView::affichageScore()
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
 * Nom: retourMenu                                          *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle: Affiche une question et un choix menu              *
 ************************************************************/
void GameView::retourMenu() const
{
    cout << "\n\nVoulez-vous quitter ou jouer ?" << endl;
    cout  << "Jouer: 0" << "\tQuitter: 1 " << endl;
}

void GameView::tabScore() const
{
    string reponse;
    cout << "\n Vous n'avez plus de vies. Fin de Jeu." << endl;
    cout << "\nVeuillez rentrez votre nom" << endl;
    cin >> reponse ;
    cout << endl;
    fstream f;
    f.open( "scores.txt", ios::out | ios::app ); // ouverture du fichier en ecriture ficNb
    if( f.fail() )
    {// Si probleme afficher une erreur
        cerr << "ouverture en lecture impossible" << endl;
        f.close();
    }
    
    f << reponse << ':' << m_model->getScore().getScoreTotal() << endl;
    
    f.close(); // fermeture du fichier
}
void GameView::perteVie()
{
    cout << " \nVous venez de perdre une vie !" << endl;
    cout << " Voulez-vous continuer ?" << endl;
    cout << " Continuer: 0 \t\t\t Quitter: 1" << endl;
}
void GameView::changementLevel()
{
    cout << "\nVous avez changé de niveau " << endl;
    cout << "Continuer :0 \t\t\t Quitter: 1" << endl;
}





