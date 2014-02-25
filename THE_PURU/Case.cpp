//
//  Case.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include <string>
#include <sstream>
#include <ctime>
#include "Case.h"
#include "Const.h"

using namespace std;

Case::Case(){
    srand((int) time(NULL));
    m_obj=ELEM[rand()%(NB_ELEM)];
}

void Case::add_o(string o){
    m_obj=o;
}

void Case::random_add(){
    srand((int) time(NULL));
    m_obj=ELEM[rand()%(NB_ELEM)];
}
string Case::toString() const
{
    ostringstream out;
    out<< m_obj;
    
    string s = out.str();
    return s;
}
ostream &operator<<(ostream &out, const Case &autre)
{
    out << autre.toString();
    return out;
}

