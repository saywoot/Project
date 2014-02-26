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
#include <sstream>
#include <string>

using namespace std;

GameView::GameView(){

}
GameView::~GameView()
{
  //destructor
}
void GameView::setModel(GameModel *model)
{
    m_model = model;
}
void GameView::affiche() const
{
    m_model->affiche();
}

void GameView::answer_move(GameModel *model) {
    string answer;
    do{
        cout << "\n\nDans quelle direction voulez-vous déplacer le mineur ? (N / NE / E / SE / S / SO / O / NO) : ";
        cin >> answer;
    }while(!(answer == "N" || answer == "NE" || answer == "E" || answer == "SE" || answer == "S" || answer == "SO" || answer == "O" || answer == "NO"));
    model->set_answer_move(answer);
}

