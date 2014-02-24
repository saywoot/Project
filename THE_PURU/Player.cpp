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

Player::Player(){
    m_obj="$$$";
    srand((int) time(NULL));
    m_p.set_pos(rand()%(WIDTH_GAME), rand()%(HEIGHT_GAME));
}

Player::Player(int x, int y, string o){
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
    m_p.set_pos(x, y);
}

Position Player::get_position(){
    return m_p;
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
    m_p.set_pos(x, y);
}

void Player::move_N(){
    
}

void Player::move_NE(){
    
}

void Player::move_E(){
    
}

void Player::move_SE(){
    
}

void Player::move_S(){
    
}

void Player::move_SO(){

}

void Player::move_O(){

}

void Player::move_NO(){
    
}

