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
#include "Const.h"

using namespace std;

Player::Player(): Case(){
    m_obj="$$$";
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


void Player::move_N(){
    this->set_pos(this->get_x(), this->get_y()-1);
}

void Player::move_NE(){
    this->set_pos(this->get_x()+1, this->get_y()-1);
}

void Player::move_E(){
    this->set_pos(this->get_x()+1, this->get_y());
}

void Player::move_SE(){
    this->set_pos(this->get_x()+1, this->get_y()+1);
}

void Player::move_S(){
    this->set_pos(this->get_x(), this->get_y()+1);
}

void Player::move_SO(){
    this->set_pos(this->get_x()-1, this->get_y()+1);
}

void Player::move_O(){
    this->set_pos(this->get_x()-1, this->get_y());
}

void Player::move_NO(){
    this->set_pos(this->get_x()-1, this->get_y()-1);
}

