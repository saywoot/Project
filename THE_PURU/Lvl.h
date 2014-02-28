//
//  Lvl.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__Lvl__
#define __THE_PURU__Lvl__

#include <iostream>
#include "Bomb.h"
#include "Case.h"

class Lvl {
private:
    int m_lvl;
    int m_nb_bomb;
    Bomb b;
    Case *matrix[18][18];
public:
    Lvl();
    //void set_lvl(int lvl, Case matrix);
    int getNb() const;
    
};

#endif /* defined(__THE_PURU__Lvl__) */
