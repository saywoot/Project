//
//  Lvl.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "Lvl.h"
#include <sstream>
#include <iostream>

using namespace std;

Lvl::Lvl(){
    m_lvl=1;
    m_nb_bomb=10;
    m_nb_bonus = 10;
}
int Lvl::getNb() const
{
    return m_nb_bomb;
}
int Lvl::getBonus() const
{
    return m_nb_bonus;
}
string Lvl::toString() const
{
    std::ostringstream out;
    out<< "Level : " << m_lvl;

    std::string s = out.str();
    return s;

}
//void Lvl::set_lvl(int lvl, Case matrix){}
