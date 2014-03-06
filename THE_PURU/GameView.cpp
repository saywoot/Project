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
    Case ***matrice = m_model->getMatrice();

    /* Affichage */
    for(int i=0; i<18; i++){
        cout << ("\t\t\t\t|---");
        for(int k=0; k<17; k++)
            cout << "|---";
        cout <<"|" << endl << "\t\t\t\t";
        for(int j=0; j<18; j++){
            if(m_model->getPlayer().get_x() == j && m_model->getPlayer().get_y() == i)
            {
                cout << "|$$$";
            }
            else if(matrice[i][j]->getObj() == "$$$" || matrice[i][j]->getObj() == "@@@" ||  matrice[i][j]->getObj() == "***")
                cout << "|" << matrice[i][j]->getObj();
            else
                cout << "| " << matrice[i][j]->getObj() <<" ";
        }
        cout << "|" <<endl ;
    }
    cout << "\t\t\t\t|---";
    for(int k=0; k<17; k++)
        cout << "|---";
    cout << "|" <<endl ;
    cout << endl;

    cout << m_model->getPlayer().toString() << "\t\t\t\t" <<m_model->getLvl().toString()  << "\n"
    << m_model->getScore().toString() << "\t\t\t" << m_model->getScore().afficheScoreTotal() << endl;
}

void GameView::answer_move(GameModel *model) {
    string answer;
    do{
        cout << "\n\nDans quelle direction voulez-vous déplacer le mineur ? (N / NE / E / SE / S / SO / O / NO) : ";
        cin >> answer;
    }while(!model->check_answer(answer));
    model->set_answer_move(answer);
}
void GameView::presentation() const
{
    cout << "Bievenue dans le jeu du Puru Puru Digger !" << endl;
    cout << "Voulez-vous jouer ou quitter ? \n" << endl;
    cout << " Quitter: 1 " << "\t" << "Jouer: 0" << endl;
}
