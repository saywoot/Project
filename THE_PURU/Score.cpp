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
string Score::toString() const
{
    std::ostringstream out;
    out<< "Le score déplacement: " << nb_deplacement;
    
    std::string s = out.str();
    return s;
}
string Score::afficheScoreTotal() const
{
    std::ostringstream out;
    out<< "Le score total: " << nb_score_total;
    
    std::string s = out.str();
    return s;
}

