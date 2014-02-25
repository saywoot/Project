//
//  GameView.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__GameView__
#define __THE_PURU__GameView__


class GameModel;

class GameView{

public:
    GameView();
    ~GameView();
    void setModel(GameModel *model);
private:
    GameModel *m_model;
};
#endif /* defined(__THE_PURU__GameView__) */
