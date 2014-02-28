#include "GameView.h"
#include "GameModel.h"
#include "Const.h"

using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    GameModel *model = new GameModel();
    GameView *view = new GameView();
    view->setModel(model);
    while(true){
    cout << model->toString() << endl;
    view->affiche();
    view->answer_move(model);
    cout << "Vous avez choisi le : "<< model->get_answer_move();
    cout << endl;
    model->direction();
    }
    
    delete view;
    delete model;
    
    return EXIT_SUCCESS;
}
