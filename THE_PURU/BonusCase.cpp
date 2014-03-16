#include "BonusCase.h"
#include "Position.h"
#include <string>
#include <cstdlib>
#include "Const.h"

using namespace std;

BonusCase::BonusCase():Case() // Appel du constructeur de la class Mère
{
    string entier = ELEM[rand()%(NB_ELEM)];
    m_obj= "-" + entier + "-";
    set_pos(rand()%WIDTH_GAME, rand()%HEIGHT_GAME);
}

void BonusCase::set_position(int x, int y){
    while(x>WIDTH_GAME || x<0 || y<0 || y>HEIGHT_GAME){
        if (x>WIDTH_GAME || x<0) {
            cout << "x : ";
            cin >> x;
        }
        if (y>HEIGHT_GAME || y<0){
            cout << "y : ";
            cin >> y;
        }
    }
    set_pos(x, y);
}
