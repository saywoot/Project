#include "GameView.h"
#include "GameModel.h"
#include "Const.h"
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    GameModel *model = new GameModel();
    GameView *view = new GameView();
    view->setModel(model);
    view->presentation();
    int message;
    int reponse;
    reponse = model->saisieChoix();
    cout << endl;

    while(true){
    switch(reponse)
    {
        case 0:
            view->retourMenu();
            message = model->saisieChoix();
            while(message == 0)
            {
                if(model->getEndGame() == true)
                {
                    view->affiche();
                    view->answer_move(model);
                    model->direction(model->get_answer_move());
                }
                else
                {
                    message = model->rejouerPartie();
                }
            }
            if(message == 1)
                return EXIT_SUCCESS;
            break;
        case 1:
            return EXIT_SUCCESS;
            break;
        case 2:
            view->affichageScore(); // affichage du score au menu si demandé
            view->retourMenu();
            cin >> reponse;
            break;

        }
    }

    delete view;
    delete model;

    return EXIT_SUCCESS;
}
