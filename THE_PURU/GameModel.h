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
#include "BonusCase.h"
#include "Const.h"
#include "Bomb.h"
#include "Lvl.h"
#include "Croix.h"
#include "Score.h"



class GameModel{
private:
    Case*** matrice; // Matrice de pointeurs
    Player *m_p;
    Lvl *m_n;
    Score *m_s;
    std::string m_answer_move;
    bool m_continuer;
public:
    GameModel();
    ~GameModel();
    void direction();
    void set_answer_move(std::string a);
    std::string get_answer_move();
    const Player& getPlayer() const;
    const Score& getScore() const;
    const Lvl& getLvl() const;
    bool check_answer(std::string a);
    int deplacement();
    bool getContinuer() const;
    void setContinuer(bool value);
    Case*** getMatrice() const;
    void setMatrice(Case*** matriceBis);
    void genereMatrice();

};


#endif /* defined(__THE_PURU__GameModel__) */

