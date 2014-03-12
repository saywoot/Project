//
//  Player.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "Player.h"
#include "Position.h"
#include <string>
#include <cstdlib>
#include <sstream>
#include "Const.h"

using namespace std;



Player::Player(): Case(){
    m_obj="$$$";
    m_vie =3;
    set_pos(rand()%(WIDTH_GAME), rand()%(HEIGHT_GAME));
}

Player::Player(int x, int y, string o): Case(){
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

void Player::set_position(int x, int y){
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

int Player::getVie() const
{
    return m_vie;
}
void Player::setVie(int nb)
{
     m_vie = nb;
}
void Player::deplacement(int x, int y)
{
    this->set_pos(this->get_x() + x, this->get_y() + y);
}
string Player::toString() const
{
    std::ostringstream out;
    out<< "Vie du joueur: " << m_vie;

    std::string s = out.str();
    return s;
}
