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
    m_p = new Player();
    
    /* Allocation dynamique de la matrice */
     matrice = new Case* [18];
    for (int i=0; i < 18 ; i++)
        matrice[i] = new Case[18];
    
    /* Allocation dynamique des 10 bombes */
    for (int i=0; i < 10 ; i++)
        matrice[rand()%(WIDTH_GAME)][rand()%(HEIGHT_GAME)] = *new Bomb();
    
    // Mis en place du joueur dans la matrice
    matrice[m_p->get_x()][m_p->get_y()] = *m_p;

    
    
}
void GameModel::affiche() const
{
    /* Affichage */
    for(int i=0; i<18; i++){
        std::cout << "\t\t\t\t|---";
        for(int k=0; k<17; k++)
            std::cout << "|---";
        std::cout <<"|" << std::endl << "\t\t\t\t";
        for(int j=0; j<18; j++){
            if(matrice[i][j].getObj() == "$$$" || matrice[i][j].getObj() == "@@@")
                std::cout << "|" << matrice[i][j];
            else
                std::cout << "| " << matrice[i][j] <<" ";
        }
        std::cout << "|" <<std::endl ;
    }
    std::cout << "\t\t\t\t|---";
    for(int k=0; k<17; k++)
        std::cout << "|---";
    std::cout << "|" <<std::endl ;

    
}
GameModel::~GameModel()
{
    for (int i=0; i < 18; i++)
        delete[] matrice[i];
    delete[] matrice;
    
    /*for (int i=0; i < 10; i++)
        delete[] m_b[i];
    delete[] m_b;*/
    
    if(m_p != NULL)
        delete m_p;
    
    /*if(m_b != NULL)
        delete m_b;*/
}
GameModel::GameModel(int w, int h, Player p, Bomb b, Lvl n)
{
    
}