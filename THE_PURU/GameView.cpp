//
//  GameView.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include "GameView.h"
#include "GameModel.h"
#include "Const.h"
#include <iostream>

using namespace std;

GameView::GameView()
{
   
}
GameView::~GameView()
{
  //destructor
}
void GameView::setModel(GameModel *model)
{
    m_model = model;
}