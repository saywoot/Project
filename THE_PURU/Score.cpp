#include "Score.h"
#include "Const.h"
#include <iostream>
#include <sstream>

using namespace std;

Score::Score()
{
    nb_deplacement = 0;
    nb_score_total = 0;
    cpt_bonnus = 0;
    m_cible = 0;
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

void Score::setCible(int c){
    m_cible=c;
}
int Score::getCible() const{
    return m_cible;
}
string Score::toString() const
{
    std::ostringstream out;
    out<< "Le score déplacement: " << nb_deplacement << "\t\tLe score cible : "<< m_cible
    <<"\nLe score total: " << nb_score_total << "\n";
    std::string s = out.str();
    return s;
}


