#include "GameView.h"
#include "GameModel.h"
#include "Const.h"

int main()
{
    srand((unsigned) time(NULL));
    GameModel *model = new GameModel();
    GameView *view = new GameView();
    view->setModel(model);
    view->affiche();
    
    delete view;
    delete model;
    
    return EXIT_SUCCESS;
}
