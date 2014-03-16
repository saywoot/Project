//
//  Position.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__Position__
#define __THE_PURU__Position__

#include <iostream>

class Position{
protected:
    int m_x;
    int m_y;

public:
    Position (); // génère aléatoirement une position
    Position (int x, int y);
    void set_x(int x);
    void set_y(int y);
    int get_x() const;
    int get_y() const;
    void set_pos(int x, int y);
};
#endif /* defined(__THE_PURU__Position__) */
