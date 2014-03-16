#include "GameView.h"
#include "GameModel.h"
#include "Const.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

GameView::GameView(){

}
GameView::~GameView()
{

}
void GameView::setModel(GameModel *model)
{
    m_model = model;
}
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

    cout <<  m_model->getScore().toString() << m_model->getLvl().toString() << "\t\t\t\t\t\t" << m_model->getPlayer().toString() << endl;
}

void GameView::answer_move(GameModel *model) {
    string answer;
    do{
        cout << "\n\nAbandonner : 1" << endl;
        cout << "Dans quelle direction voulez-vous déplacer le mineur ? (N / NE / E / SE / S / SO / O / NO) : " << endl;
        cin >> answer;
    }while(!model->check_answer(answer));
    model->set_answer_move(answer);
}
void GameView::presentation() const
{
    cout <<"  ___   _     _   ___   _     _       ___   _     _   ___   _     _      ___    _    ____      ____"                           << endl;
    cout <<" /   \\ | |   | | /   \\ | |   | |     /   \\ | |   | | /   \\ | |   | |    |   \\  | |  / __ \\    / __ \\"                   << endl;
    cout <<"|  _  \\| |   | ||  _  \\| |   | |    |  _  \\| |   | ||  _  \\| |   | |    | |\\ \\ | | / /  \\_\\  / /  \\_\\"               << endl;
    cout <<"| |_| /| |   | || |_| /| |   | | __ | |_| /| |   | || |_| /| |   | | __ | | | || || |    __ | |    __"                         << endl;
    cout <<"|  __/ | |   | ||  __/ | |   | ||__||  __/ | |   | ||  __/ | |   | ||__|| | | || || |   | _|| |   | _|"                        << endl;
    cout <<"| |    | |   | ||   \\  | |   | |    | |    | |   | ||   \\  | |   | |    | | | || || |   | | | |   | |"                       << endl;
    cout <<"| |    | \\___/ || |\\ \\ | \\___/ |    | |    | \\___/ || |\\ \\ | \\___/ |    | |/ / | | \\ \\__/ |  \\ \\__/ |"             << endl;
    cout <<"|_|     \\_____/ |_| \\_\\ \\_____/     |_|     \\_____/ |_| \\_\\ \\_____/     |___/  |_|  \\____/    \\____/"                << endl;
    cout << endl;
    cout << endl;
    cout << "Voulez-vous jouer ou quitter ? \n" << endl;
    cout  << "Jouer: 0" << "\tQuitter: 1 " << "MeilleurScores: 2" << endl;
}
void GameView::rejouer() const
{
    cout << "Vous avez perdu ou décider d'abandonner" << endl;
    cout << " Voulez rejouer ? " << endl;
    cout << " Quitter: 1 " << "\t" << "Rejouer: 0" << endl;
}
void GameView::affichageScore() const
{
    fstream f;
    f.open("/Users/Etienne/Project/THE_PURU/scores.txt", ios::in); // ouverture du fichier en ecriture ficNb
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
void GameView::retourMenu() const
{
    cout << "\n\nVoulez-vous quitter ou jouer ?" << endl;
    cout  << "Jouer: 0" << "\tQuitter: 1 " << endl;
}




