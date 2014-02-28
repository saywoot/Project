#include "Score.h"
#include "Const.h"
#include <iostream>

using namespace std;

Score::Score()
{
    nb_deplacement = 0;
    cpt_bonnus = 0;
}
void Score::setDeplacement(int deplacement)
{
    nb_deplacement = deplacement;
}
int Score::getDeplacement() const
{
    return nb_deplacement;
}