#include "Score.h"
#include "Const.h"
#include "Lvl.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Score::Score()
{
    nb_deplacement = 0;
    nb_score_total = 0;
    m_cible = 10;
}
void Score::setDeplacement(int deplacement)
{
    nb_deplacement = deplacement;
}
void Score::setScoreTotal(int score)
{
    nb_score_total = score;
}
int Score::getDeplacement() const
{
    return nb_deplacement;
}
int Score::getScoreTotal() const
{
    return nb_score_total;
}
void Score::setCible(int c)
{
    m_cible = c;
}
int Score::getCible() const
{
    return m_cible;
}
void Score::tabScore()
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

    f << reponse << ':' << getScoreTotal() << endl;

    f.close(); // fermeture du fichier
}



