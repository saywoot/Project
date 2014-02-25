//
//  Case.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include <string>
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

