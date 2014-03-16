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
    int message;
    cin >> reponse;
    cout << endl;
    
    while(true){
    switch(reponse)
    {
        case 0:
            cout << "Voulez-vous jouer ou abandonner ?" << endl;
            cout << "Jouer: 0 \t Abandonner: 1" << endl;
            cin >> message;
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
                    view -> affichageScore(); // Si la partie est finie, on affiche les meilleurs scores.
                    view->rejouer();
                    cin >> message;
                    model->setEndGame(true);
                    model->initLevel();
                    model->genereMatrice(); // VIENS D'ETRE AJOUTER
                }
            }
            if(message == 1)
                return EXIT_SUCCESS;
            
            break;
        case 1:
            return EXIT_SUCCESS;
            break;
        case 2:
            view->affichageScore();
            view->retourMenu();
            cin >> reponse;
            break;

        }
    }
    
    

    delete view;
    delete model;

    return EXIT_SUCCESS;
}
