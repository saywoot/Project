#include "GameView.h"
#include "GameModel.h"
#include <cstdlib>
#include "Const.h"
#include <stdio.h>

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    GameModel *model = new GameModel();
    GameView *view = new GameView();
    view->setModel(model);
    view->presentation();

    int reponse;
    cin >> reponse;

    while(reponse == 0)
    {
        if(model->getEndGame() == true)
        {
            view->affiche();
            view->answer_move(model);
            model->direction(model->get_answer_move());
        }
        else
        {
            view->rejouer();
            cin >> reponse;
            model->setEndGame(true);
            model->initLevel();
        }
    }
    delete view;
    delete model;

    return EXIT_SUCCESS;
}
