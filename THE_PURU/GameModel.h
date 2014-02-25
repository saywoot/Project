//
//  GameModel.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__GameModel__
#define __THE_PURU__GameModel__

#include <iostream>
#include "Player.h"
#include "Case.h"
#include "Const.h"
#include "Bomb.h"
#include "Lvl.h"

class GameModel{
private:
    Case **matrix;
    Player m_p;
    Bomb m_b;
    Lvl m_n;
public:
    GameModel();
    GameModel(int w, int h, Player p, Bomb m_b, Lvl n);
};

#endif /* defined(__THE_PURU__GameModel__) */

