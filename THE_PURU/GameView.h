//
//  GameView.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__GameView__
#define __THE_PURU__GameView__

#include <string>

class GameModel;
class Case;

class GameView{

public:
    GameView();
    ~GameView();
    void setModel(GameModel *model);
    void affiche() const;
    void presentation() const;
    void answer_move(GameModel *model);
    static void rejouer();
    static void affichageScore();
    void retourMenu() const;
    std::string afficheBonus() const;
    std::string afficheScore() const;
    std::string viePlayer() const;
    void tabScore() const;
    static void perteVie();
    static void changementLevel();

private:
    GameModel *m_model;
};
#endif /* defined(__THE_PURU__GameView__) */
