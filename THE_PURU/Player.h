//
//  Player.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__Player__
#define __THE_PURU__Player__

#include <iostream>

#include "Case.h"
#include "Position.h"

class Player : public Case{
private:
    Position m_p;
public:
    Player();
    Player(int x, int y, std::string o);
    
    Position get_position();
    void set_position(int x, int y);
    void move_N();
    void move_NE();
    void move_E();
    void move_SE();
    void move_S();
    void move_SO();
    void move_O();
    void move_NO();
};

#endif /* defined(__THE_PURU__Player__) */
