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

    /*Allocation dynamique des pointeurs qui vont contenir des cases */
    matrice = new Case** [18];
    for (int i=0; i < 18 ; i++)
        matrice[i] = new Case*[18];

    /* Allocation des cases */
    for(int i=0; i<18; i++){
        for(int j=0; j<18; j++)
            matrice[i][j] = new Case();
    }

    /* Allocation dynamique des 10 bombes */
    for (int i=0; i < m_n->getNb() ; i++){
        int x = rand()%(WIDTH_GAME);            // Affectation aléatoire d'un entier
        int y = rand()%(HEIGHT_GAME);           // Affectation aléatoire d'un entier
        delete matrice[x][y];                   // Désallocation de la case pour mettre la bombe
        matrice[x][y] = new Bomb();             // Appel du construteur de Bomb pour remplir la case
    }

    /*  for (int i=0; i < m_n->getBonus() ; i++){
        int x = rand()%(WIDTH_GAME);            // Affectation aléatoire d'un entier
        int y = rand()%(HEIGHT_GAME);           // Affectation aléatoire d'un entier
        delete matrice[x][y];                   // Désallocation de la case pour mettre le bonus
        matrice[x][y] = new BonusCase();             // Appel du construteur de Bonus pour remplir la case
    }*/

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

void GameModel::direction(){
    int nb_cases;                                                   // Initialisation d'un entier nb_cases
    if(m_answer_move=="N"){
        m_p->move_N();                                              // Mouvement vers le Nord du joueur
        nb_cases= deplacement();                                    // On stocke la valeur de la case suivante

        if((m_p->get_y() +1 - nb_cases >= 0) && nb_cases != -1)     // Si la position du joueur + la valeur de nb_case est valide et ne dépasse pas la taille de la matrice
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);    // Incrémentation du nombre de déplacement
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);      // Incrémentation du score total

            int i = 1;                                              // Initialisation de i à 1

            while(i < nb_cases && deplacement() != -1){             // Tant que le joueur n'a pas atteint la case et que la case suivante est un chiffre
                delete matrice[m_p->get_y()][m_p->get_x()];         // On libére la case du joueur
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();  // Appel du constructeur de la croix pour la mettre dans la case précédente du joueur
                m_p->move_N();                                      // Puis on fait monter le joueur à nouveau
                i++;                                                // On incrémente i
            }
            if(deplacement() != -1){                                // Si le joueur a atteint le nb_case alors on supprime et on met une croix
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);                                   // Sinon c'est qu'il a rencontré une bombe ou sa "queue" on regénére la matrice
            }

        }
        else{
            std::cout << "Fin de jeu " << std::endl;                // Affiche Fin de jeu ( perte de vie )
            m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
            m_s->setDeplacement(0);                                 // On remet le score déplacement à O
            setContinuer(false);                                    // On met la valeur à faux pour regénérer
        }
    }
    else if(m_answer_move=="NE"){
        m_p->move_NE();
        nb_cases=deplacement();

        if((m_p->get_y() +1 - nb_cases >= 0) && ((m_p->get_x() -1 + nb_cases < WIDTH_GAME)))
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);

            int i = 1;

           while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_NE();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }

        }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie() - 1);
            m_s->setDeplacement(0);
            setContinuer(false);
        }

    }
    else if(m_answer_move=="E"){
        m_p->move_E();
        nb_cases=deplacement();
        if(((m_p->get_x() -1 + nb_cases < WIDTH_GAME)))
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);

            int i = 1;

             while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_E();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }

        }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie() - 1);
            m_s->setDeplacement(0);
            setContinuer(false);
        }
    }
    else if(m_answer_move=="SE"){
        m_p->move_SE();
        nb_cases=deplacement();
        if((m_p->get_y() -1 + nb_cases < HEIGHT_GAME) && ((m_p->get_x() -1 + nb_cases < WIDTH_GAME)))
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);

            int i = 1;
                 while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_SE();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }
        }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie() - 1);
            m_s->setDeplacement(0);
            setContinuer(false);
        }
    }
    else if(m_answer_move=="S"){
        m_p->move_S();
        nb_cases=deplacement();
        if(((m_p->get_y() -1 + nb_cases < HEIGHT_GAME)))
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);

            int i = 1;

            while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_S();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }
      }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie()-1);
            m_s->setDeplacement(0);
            setContinuer(false);
        }
    }
    else if(m_answer_move=="SO"){
        m_p->move_SO();
        nb_cases=deplacement();
         if((m_p->get_y() -1 + nb_cases < HEIGHT_GAME) && ((m_p->get_x() +1 - nb_cases >= 0)))
        {

            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);
            int i = 1;

            while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_SO();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }

      }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie() - 1);
            m_s->setDeplacement(0);
            setContinuer(false);
    }

    }
    else if(m_answer_move=="O"){
        m_p->move_O();
        nb_cases=deplacement();
         if((m_p->get_x() +1 - nb_cases >= 0))
         {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);
            int i = 1;


            while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_O();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }
      }
         else{
             std::cout << "Fin de jeu " << std::endl;
             m_p->setVie(m_p->getVie() - 1);
             m_s->setDeplacement(0);
             setContinuer(false);
         }
    }
    else if(m_answer_move=="NO"){
        m_p->move_NO();
        nb_cases=deplacement();
       if((m_p->get_y() +1 - nb_cases >= 0) && ((m_p->get_x() +1 - nb_cases >= 0)))
        {
            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases);
            int i = 1;


            while(i < nb_cases && deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                m_p->move_O();
                i++;
            }
            if(deplacement() != -1){
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
            }
            else {
                m_p->setVie(m_p->getVie() - 1);                         // On décremente la vie
                m_s->setDeplacement(0);                                 // On remet le score déplacement à O
                setContinuer(false);
            }
        }
        else{
            std::cout << "Fin de jeu " << std::endl;
            m_p->setVie(m_p->getVie() - 1);
            m_s->setDeplacement(0);
            setContinuer(false);
        }
    }
}



int GameModel::deplacement(){
    string obj = matrice[m_p->get_y()][m_p->get_x()]->getObj();

    if(obj != "X" && obj != "@@@" && obj != m_p->getObj()){
        istringstream iss(obj);
        int nombre_cases;
        iss >> nombre_cases;
        cout << "Nombre_case : " << nombre_cases << endl;
        return nombre_cases;
    }
   /* else if(obj == "***"){
        int valeur = ELEM[rand()%(NB_ELEM)] + 4;
        return valeur;
    }*/
    else
        return -1;
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

    for (int i=0; i < m_n->getNb() ; i++){
        int x = rand()%(WIDTH_GAME);
        int y = rand()%(HEIGHT_GAME);
        delete matrice[x][y];
        matrice[x][y] = new Bomb();
        }

   /* for (int i=0; i < m_n->getBonus() ; i++){
        int x = rand()%(WIDTH_GAME);            // Affectation aléatoire d'un entier
        int y = rand()%(HEIGHT_GAME);           // Affectation aléatoire d'un entier
        delete matrice[x][y];                   // Désallocation de la case pour mettre le bonus
        matrice[x][y] = new BonusCase();             // Appel du construteur de Bonus pour remplir la case
    }*/
        m_p->set_position(rand()%WIDTH_GAME,rand()%HEIGHT_GAME);

        setMatrice(matrice);
}












