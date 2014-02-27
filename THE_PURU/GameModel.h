//
//  GameModel.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__GameModel__
#define __THE_PURU__GameModel__

#include <iostream>
#include <string>
#include <map>
#include "Player.h"
#include "Case.h"
#include "Const.h"
#include "Bomb.h"
#include "Lvl.h"
#include "Croix.h"



class GameModel{
private:
    Case **matrice;
    Player *m_p;
    Lvl *m_n;
    std::string m_answer_move;
public:
    GameModel();
    GameModel(int w, int h, Player p, Bomb b, Lvl n);
    ~GameModel();
    void affiche() const;
    void direction();
    void set_answer_move(std::string a);
    std::string get_answer_move();
    bool check_answer(std::string a);
    int deplacement();
    void set_last_pos(int x, int y);
   // bool endGame();
};

#endif /* defined(__THE_PURU__GameModel__) */

