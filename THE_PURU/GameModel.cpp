//
//  GameModel.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include "GameModel.h"
#include "GameView.h"
#include "Const.h"


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
    // pour faire le teste des restriction de mouvement :
    //m_p->set_position(0, 17);
    matrice[m_p->get_y()][m_p->get_x()] = *m_p;
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
GameModel::GameModel(int w, int h, Player p, Bomb b, Lvl n){
    
}

void GameModel::direction(){
    int nb_cases;
    if(m_answer_move=="N"){
        m_p->move_N();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            std::cout <<"valeur : " << deplacement() << std::endl;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_N();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="NE"){
        m_p->move_NE();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_NE();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="E"){
        m_p->move_E();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_E();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="SE"){
        m_p->move_SE();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_SE();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="S"){
        m_p->move_S();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_S();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="SO"){
        m_p->move_SO();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_SO();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="O"){
        m_p->move_O();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_O();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else if(m_answer_move=="NO"){
        m_p->move_NO();
        nb_cases=deplacement();
        if(nb_cases == -1)
            std::cout << "ENDGAME" << std::endl;
        //provisoire il faut faire une méthode endgame qui renvoit un booléen quand je joueur à perdu
        else{
            int i = 1;
            matrice[m_p->get_y()][m_p->get_x()] = *m_p;
            while(i<nb_cases){
                std::cout << "i : " << i << std::endl;
                m_p->move_NO();
                matrice[m_p->get_y()][m_p->get_x()] = *m_p;
                ++i;
            }
        }
    }
    else
        exit(-1);
}

int GameModel::deplacement(){
    if(matrice[m_p->get_y()][m_p->get_x()].getObj() != "X" &&
       matrice[m_p->get_y()][m_p->get_x()].getObj() != "@@@" &&
       matrice[m_p->get_y()][m_p->get_x()].getObj() != m_p->getObj()){
        std::istringstream iss(matrice[m_p->get_y()][m_p->get_x()].getObj());
        int nombre_cases;
        iss >> nombre_cases;
        std::cout << "Nombre_case : " << nombre_cases << std::endl;
        return nombre_cases;
    }
    else
        return -1;
}

void GameModel::set_last_pos(int x, int y){

}


void GameModel::set_answer_move(std::string a){
    m_answer_move=a;
}

std::string GameModel::get_answer_move(){
    return m_answer_move;
}

bool GameModel::check_answer(std::string a){
    if(a == "N" || a == "NE" || a == "E" || a == "SE" || a == "S" || a == "SO" ||
       a == "O" || a == "NO"){
        if ((a == "N" || a == "NE" || a == "NO") && m_p->get_y() == 0){
            return false;
        }
        else if ((a == "S" || a == "SO" || a == "SE") && m_p->get_y() == HEIGHT_GAME-1){
            return false;
        }
        else if ((a == "O" || a == "NO" || a == "SO") && m_p->get_x() == 0){
            return false;
        }
        else if ((a == "E" || a == "NE" || a == "SE") && m_p->get_x() == WIDTH_GAME-1){
            return false;
        }
        else
            return true;
    }
    else
        return false;
}



