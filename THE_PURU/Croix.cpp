//
//  Bomb.cpp
//  THE_PURU
//
//  Created by Etienne on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "Croix.h"
#include "Position.h"
#include <string>
#include <cstdlib>
#include "Const.h"

using namespace std;

Croix::Croix():Case() // Appel du constructeur de la class Mère
{
    m_obj=" ";
    set_pos(rand()%WIDTH_GAME, rand()%HEIGHT_GAME);
}

void Croix::set_position(int x, int y){
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
