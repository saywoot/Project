//
//  GameModel.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "GameModel.h"

GameModel::GameModel()
{
    /* Allocation dynamique */
     matrice = new Case* [18];
    for (int i=0; i < 18 ; i++)
        matrice[i] = new Case[18];
    
    /* Affichage */
    for (int i=0; i < 18 ; i++) {
        for (int j=0; j < 18 ; j++)
            std::cout << matrice[i][j] << " ";
        std::cout << std::endl;
    }
    
}
GameModel::~GameModel()
{
    for (int i=0; i < 18; i++)
        delete[] matrice[i];
    delete[] matrice;
}
GameModel::GameModel(int w, int h, Player p, Bomb b, Lvl n)
{
    
}