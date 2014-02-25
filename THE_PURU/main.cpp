#include "GameView.h"
#include "GameModel.h"
#include "Const.h"

int main()
{

    GameModel *model = new GameModel();
    GameView *view = new GameView();
    view->setModel(model);
    
    
    delete view;
    delete model;
    
    return EXIT_SUCCESS;
}
