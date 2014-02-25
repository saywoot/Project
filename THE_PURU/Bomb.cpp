//
//  Bomb.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "Bomb.h"
#include "Position.h"
#include <string>
#include "Const.h"

using namespace std;

Bomb::Bomb():Case(){
    srand((int) time(NULL));
    m_obj="@@@";
    m_p.set_pos(rand()%WIDTH_GAME, rand()%HEIGHT_GAME);
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
    m_p.set_pos(x, y);
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
    m_p.set_pos(x, y);
}