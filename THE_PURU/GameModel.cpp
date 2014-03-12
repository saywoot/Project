//
//  GameModel.cpp
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "GameModel.h"
#include "GameView.h"
#include "Const.h"

using namespace std;

GameModel::GameModel()
{
    m_p = new Player();                     // Appel du constructeur du player
    m_n = new Lvl();                        // Appel du constructeur de Level
    m_s = new Score();                      // Appel du constructeur de Score

    m_b = new Bomb*[10];
    for(int i=0; i<10; i++)
    {
        m_b[i] = new Bomb();
    }

    /*Allocation dynamique des pointeurs qui vont contenir des cases */
    matrice = new Case** [18];
    for (int i=0; i < 18 ; i++)
        matrice[i] = new Case*[18];

    /* Allocation des cases */
    for(int i=0; i<18; i++){
        for(int j=0; j<18; j++)
            matrice[i][j] = new Case();
    }

    /* Allocation dynamique des 10 bombes*/
    for (int i=0; i < m_n->getNb() ; i++){
        int x = m_b[i]->get_x();
        int y = m_b[i]->get_y();
        delete matrice[m_b[i]->get_x()][m_b[i]->get_y()];                   // Désallocation de la case pour mettre la bombe
        matrice[x][y] = m_b[i];                                             // Appel du construteur de Bomb pour remplir la case
    }


     for (int i=0; i < m_n->getBonus() ; i++){
        int x = rand()%(WIDTH_GAME);            // Affectation aléatoire d'un entier
        int y = rand()%(HEIGHT_GAME);           // Affectation aléatoire d'un entier
        delete matrice[x][y];                   // Désallocation de la case pour mettre le bonus
        matrice[x][y] = new BonusCase();             // Appel du construteur de Bonus pour remplir la case
    }

}
GameModel::~GameModel()
{
    /* Allocation dynamique des cases */
    for (int i=0; i < 18; i++){
        for(int j=0; j < 18; j++)
            delete matrice[i][j];
        delete[] matrice[i];
    }
    delete[] matrice;                           // Désallocation de la matrice

    /* Désallocation du score */
    if(m_s != NULL)
        delete m_s;

}
void GameModel::direction(string answer){
    if(answer=="N")
        move(0,-1);
    if(answer=="S")
        move(0, 1);
    if(answer=="E")
        move(1,0);
    if(answer=="O")
        move(-1, 0);
    if(answer=="SE")
        move(1, 1);
    if(answer=="SO")
        move(-1, 1);
    if(answer=="NO")
        move(-1, -1);
    if(answer=="NE")
        move(1,-1);
}
void GameModel::set_answer_move(std::string a){
    m_answer_move=a;
}

std::string GameModel::get_answer_move(){
    return m_answer_move;
}

bool GameModel::check_answer(std::string a){
    if(a == "N" || a == "NE" || a == "E" || a == "SE" || a == "S" || a == "SO" ||
       a == "O" || a == "NO"){
        if ((a == "N" || a == "NE" || a == "NO") && m_p->get_y() == 0){
            return false;
        }
        else if ((a == "S" || a == "SO" || a == "SE") && m_p->get_y() == HEIGHT_GAME-1){
            return false;
        }
        else if ((a == "O" || a == "NO" || a == "SO") && m_p->get_x() == 0){
            return false;
        }
        else if ((a == "E" || a == "NE" || a == "SE") && m_p->get_x() == WIDTH_GAME-1){
            return false;
        }
        else
            return true;
    }
    else
        return false;
}

void GameModel::move(int pos_x, int pos_y)
{
     delete matrice[m_p->get_y()][m_p->get_x()];
     matrice[m_p->get_y()][m_p->get_x()] = new Croix();
     m_p->deplacement(pos_x,pos_y);
     nb_cases = deplacement();

        if(nb_cases != -1 ){                                       // Mouvement vers le Nord du joueur

            m_s->setDeplacement(m_s->getDeplacement()+nb_cases); // Incrémentation du nombre de déplacement
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases); // Incrémentation du score total
            i = 1;                                              // Initialisation de i à 1

            while(i < nb_cases && deplacement() != -1)
            {                                                       // Tant que le joueur n'a pas atteint la case et que la case suivante est un chiffre
                delete matrice[m_p->get_y()][m_p->get_x()];         // On libére la case du joueur
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();  // Appel du constructeur de la croix pour la mettre dans la case précédente du joueur
                m_p->deplacement(pos_x, pos_y);                                      // Puis on fait monter le joueur à nouveau
                i++;                                                // On incrémente i
            }
            if(deplacement() != -1){                                // Si le joueur a atteint le nb_case alors on supprime et on met une croix
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else{
                m_p->setVie(m_p->getVie() - 1); // On décremente la vie
                m_s->setDeplacement(0); // On remet le score déplacement à O
                setContinuer(false); // Sinon c'est qu'il a rencontré une bombe ou sa "queue" on regénére la matrice                            // Sinon c'est qu'il a rencontré une bombe ou sa "queue" on regénére la matrice
            }
        }
        else{
            m_p->setVie(m_p->getVie() - 1); // On décremente la vie
            m_s->setDeplacement(0); // On remet le score déplacement à O
            setContinuer(false); // Sinon c'est qu'il a rencontré une bombe ou sa "queue" on regénére la matrice
        }
}



int GameModel::deplacement(){
    string obj;
    if(m_p->get_x() >= 0 && m_p->get_x() < WIDTH_GAME && m_p->get_y() >= 0 && m_p->get_y() < HEIGHT_GAME){
         obj = matrice[m_p->get_y()][m_p->get_x()]->getObj();
    }
    else{
        return -1;
    }
    if(obj != " " && obj != "@@@" && obj != m_p->getObj() && obj != "***")
    {
        istringstream iss(obj);
        int nombre_cases;
        iss >> nombre_cases;
        // cout << "Nombre_case : " << nombre_cases << endl;
        return nombre_cases;
    }
    else if(obj == "***"){
        m_s->setScoreTotal(m_s->getScoreTotal()+ 10); // Incrémentation du score total
        return 1;
    }
    else
        return -1;
}


// Fonction permettant l'affichage de l'objet
// retourne un string


// Getters //
const Player& GameModel::getPlayer() const
{
    return *m_p;
}

const Score& GameModel::getScore() const
{
    return *m_s;
}

const Lvl& GameModel::getLvl() const
{
    return *m_n;
}
Case*** GameModel::getMatrice() const{

    return matrice;
}
bool GameModel::getContinuer() const
{
    return m_continuer;
}
void GameModel::setContinuer(bool value)
{
    m_continuer = value;
}
void GameModel::setMatrice(Case*** matriceBis)
{
    matrice = matriceBis;
}

void GameModel::genereMatrice(){

    for (int i=0; i < 18; i++){
        for(int j=0; j < 18; j++)
            delete matrice[i][j];
    }

     for(int i=0; i<18; i++){
        for(int j=0; j<18; j++)
            matrice[i][j] = new Case();
    }

    for(int i=0; i<10; i++)
    {
        m_b[i] = new Bomb();
    }

      /* Allocation dynamique des 10 bombes*/
    for (int i=0; i < m_n->getNb() ; i++){
        int x = m_b[i]->get_x();
        int y = m_b[i]->get_y();
        delete matrice[m_b[i]->get_x()][m_b[i]->get_y()];                   // Désallocation de la case pour mettre la bombe
        matrice[x][y] = m_b[i];                                             // Appel du construteur de Bomb pour remplir la case
    }

    for (int i=0; i < m_n->getBonus() ; i++){
        int x = rand()%(WIDTH_GAME);            // Affectation aléatoire d'un entier
        int y = rand()%(HEIGHT_GAME);           // Affectation aléatoire d'un entier
        delete matrice[x][y];                   // Désallocation de la case pour mettre le bonus
        matrice[x][y] = new BonusCase();             // Appel du construteur de Bonus pour remplir la case
    }
        m_p->set_position(rand()%WIDTH_GAME,rand()%HEIGHT_GAME);

        setMatrice(matrice);
}












