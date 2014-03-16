#include "Bomb.h"
#include "Position.h"
#include <string>
#include <cstdlib>
#include "Const.h"

using namespace std;

Bomb::Bomb():Case() // Appel du constructeur de la class Mère
{
    m_obj = "@@@";
    set_pos(rand()%(WIDTH_GAME), rand()%(HEIGHT_GAME));
}

Bomb::Bomb(int x, int y, string o):Case(){
    m_obj=o;
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

void Bomb::set_position(int x, int y){
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
bool Bomb::operator==(const Bomb& autre)
{
    if(this != &autre)
        return false;
    else
        return(this->get_x() == autre.get_x() && this->get_y() == autre.get_y());
}
