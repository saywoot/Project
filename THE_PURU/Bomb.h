//
//  Bomb.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__Bomb__
#define __THE_PURU__Bomb__

#include <iostream>
#include <string>

#include "Position.h"
#include "Case.h"

class Bomb : public Case{
private:
   // Position m_p;
public:
    Bomb();
    Bomb(int x, int y, std::string o);
    
    void set_position(int x, int y);
};

#endif /* defined(__THE_PURU__Bomb__) */
