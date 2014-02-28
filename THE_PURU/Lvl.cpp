//
//  Lvl.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "Lvl.h"

Lvl::Lvl(){
    m_lvl=1;
    m_nb_bomb=10;
}
int Lvl::getNb() const
{
    return m_nb_bomb;
}
//void Lvl::set_lvl(int lvl, Case matrix){}