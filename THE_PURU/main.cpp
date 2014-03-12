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
    int reponse;
    view->setModel(model);
    model->setContinuer(true);
    view->presentation();
    cin >> reponse;

    while(reponse == 0){
        view->affiche();
        view->answer_move(model);
        model->direction(model->get_answer_move());
        if(model->getContinuer() == false)
        {
            model->genereMatrice();
            model->setContinuer(true);
        }
    }
    delete view;
    delete model;

    return EXIT_SUCCESS;
}
