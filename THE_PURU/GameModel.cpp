#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "GameModel.h"
#include "GameView.h"
#include "Const.h"

using namespace std;

/************************************************************
 * Nom: GameModel                                           *
 ************************************************************
 * Type: Constructeur                                       *
 ************************************************************
 * Rôle: Initialise les pointeurs contenus et créé les cases*
 *      contenues matrice et toutes les cases avec les      *
 *      différents objets. Initialise le tableau de bombes, *
 *      le tableau de bonusCase également et place le joueur*
 *      dans la matrice.                                    *
 ************************************************************/
GameModel::GameModel()
{
    m_p = new Player();                     // Appel du constructeur du player
    m_n = new Lvl();                        // Appel du constructeur de Level
    m_s = new Score();                      // Appel du constructeur de Score
    fin = true;

    m_b = new Bomb*[30];
    for(int i=0; i<m_n->getNb(); i++)
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
/**************************************************************
 * Nom: ~GameModel                                            *
 **************************************************************
 * Type: Destructeur                                          *
 **************************************************************
 * Rôle: Permet de désallouer tous les pointeurs contenus dans*
 *     contenus dans la matrice, et de désallouer les cases   *
 *      de la matrice. Désalloue également le joueur.         *
 **************************************************************/
GameModel::~GameModel()
{
    /* Allocation dynamique des cases */
    for (int i=0; i < 18; i++){
        for(int j=0; j < 18; j++)
            delete matrice[i][j];
        delete[] matrice[i];
    }
    delete[] matrice;                           // Désallocation de la matrice

    delete [] m_b;

    /* Désallocation du score */
    if(m_s != NULL)
        delete m_s;
    if(m_p != NULL)
        delete m_p;
    if(m_n != NULL)
        delete m_n;
}
/*************************************************************
 * Nom: direction                                            *
 *************************************************************
 * Type: void                                                *
 *************************************************************
 * Paramètres: answer de type string                         *
 *************************************************************
 * Rôle:  Fonction qui appelle la fonction move avec des     *
 *       paramètres différents qui changent en fonction de la*
 *       direction entrée par l'utilisateur.                 *
 *************************************************************/
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
/************************************************************
 * Nom: set_answer_move                                     *
 ************************************************************
 * Type: void  (setter)                                     *
 ************************************************************
 * @param string                                            *
 ************************************************************
 * Rôle: Affecte une chaine de caractère                    *
 ************************************************************/
void GameModel::set_answer_move(std::string a){
    m_answer_move=a;
}
/************************************************************
 * Nom: get_answer_move                                     *
 ************************************************************
 * Type: string (getter)                                    *
 ************************************************************
 * Rôle: Retourne la valeur de la varaible m_answer_move    *
 ************************************************************/
std::string GameModel::get_answer_move(){
    return m_answer_move;
}
/************************************************************
 * Nom: check_answer                                        *
 ************************************************************
 * Type: bool                                               *
 ************************************************************
 * @param string                                            *
 ************************************************************
 * Rôle:  Retourne vrai ou faux en fonction de la saisie de *
 *     l'utilisateur au clavier lors de la demande de       *
 *     la direction voulue.                                 *
 ************************************************************/
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
    /********************************************************
     * Si le joueur décide de quitter en cours de partie on *
     *revient au menu.                                      *
     ********************************************************/
    else if(a == "1")
    {
        fin = false;
        return true;
    }
    else
        return false;
}

void GameModel::tabScore()
{
    string reponse;
    GameView::plusDeVie();
    cin >> reponse ;
    cout << endl;
    fstream f;
    f.open( "scores.txt", ios::out | ios::app ); // ouverture du fichier en ecriture ficNb
    if( f.fail() )
    {// Si probleme afficher une erreur
        cerr << "ouverture en lecture impossible" << endl;
        f.close();
    }
    
    f << reponse << ':' << getScore().getScoreTotal() << endl;
    
    f.close(); // fermeture du fichier
}
/*************************************************************
 * Nom: endGame                                              *
 *************************************************************
 * Type: bool                                                *
 *************************************************************
 * Rôle:  Fonction qui vérifie que la vie du joueur n'est pas*
 * inférieur à 0. Retourne la valeur de fin et appelle       *
 *      la fonction tabScore si la parite est finie          *
 *************************************************************/
bool GameModel::endGame()
{
    if(m_p->getVie() <= 0){
        fin = false;
        tabScore();
        return fin;
    }
    return fin;
}
/************************************************************
 * Nom: setEndGame                                          *
 ************************************************************
 * Type: void (setter)                                      *
 ************************************************************
 * @param bool choix                                        *
 ************************************************************
 * Rôle:  Affecte la valeur de choix à la variable fin      *
 ************************************************************/
void GameModel::setEndGame(bool choix)
{
    fin = choix;
}
/************************************************************
 * Nom: getEndGame                                          *
 ************************************************************
 * Type: bool   (getter)                                    *
 ************************************************************
 * Rôle:  Retourne la variable fin                          *
 ************************************************************/
bool GameModel::getEndGame()
{
    return fin;
}
/**************************************************************
 * Nom: initLevel                                             *
 **************************************************************
 * Type: void                                                 *
 **************************************************************
 * Rôle:  Fonction appelée lorsque l'on commence un niveau    *
 *       Elle appelle les fonctionsdes classes Score, Lvl et  *
 *       Player et affecte des valeurs de début de parties au *
 *       différents attributs (bonus à 0, level à 1).         *
 **************************************************************/
void GameModel::initLevel()
{
    m_n->setLevel(1);
    m_n->initBonus();
    m_s->setCible(10);
    m_s->setScoreTotal(0);
    m_p->setVie(3);
}
/************************************************************
 * Nom: perteVie                                            *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle:  Fonction appelée lors de la perte d'une vie. Elle *
 *       décrémente la vie et gère le cas où le joueur veut *
 *       continuer et celui ou celui-ci veut s'arrêter      *
 ************************************************************/
void GameModel::perteVie()
{
    int reponse;
    m_p->setVie(m_p->getVie() - 1); // On décremente la vie
    m_s->setDeplacement(0); // On remet le score déplacement à O


    if(m_p->getVie() > 0){
        GameView::perteVie();
        cin >> reponse;

        if(reponse == 0){
            genereMatrice();
            endGame();
        }
        else
        {
            set_answer_move("1");
            setEndGame(false);
        }
    }
    else
        endGame();
}
/************************************************************
 * Nom: move                                                *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Paramètres: variable pos_x,pos_y de type integer         *
 ************************************************************
 * Rôle:  Focntion principale du déplacement. Elle permet de*
 *       déplacer le joueur, vérifier que le joueur ne      *
 *       rencontre pas une bombe ou ne sorte de la matrice  *
 ************************************************************/
void GameModel::move(int pos_x, int pos_y)
{
    int x = m_p->get_x();
    int y = m_p->get_y();
     delete matrice[m_p->get_y()][m_p->get_x()];
     matrice[m_p->get_y()][m_p->get_x()] = new Croix();
     m_p->deplacement(pos_x,pos_y);
     nb_cases = deplacement();

	  string obj = matrice[m_p->get_y()][m_p->get_x()]->getObj();  // Test si la case suivante, la premiere, est une bombe
        if(obj == "@@@" || obj == " "){
            nb_cases = 0;
        }

		 if(nb_cases == 0)                                          // Si c'est une bombe on recule
        {
            m_p->set_pos(x, y);
        }
        else if(nb_cases != -1 ){

            m_s->setDeplacement(m_s->getDeplacement()+nb_cases);    // Incrémentation du nombre de déplacement
            m_s->setScoreTotal(m_s->getScoreTotal()+nb_cases*10);   // Incrémentation du score total

            i = 1;                                                  // Initialisation de i à 1

            while(i < nb_cases && deplacement() != -1)
            {
                delete matrice[m_p->get_y()][m_p->get_x()];         // On libére la case du joueur
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();  // Appel du constructeur de la croix pour la mettre dans la case précédente du joueur
                m_p->deplacement(pos_x, pos_y);                                      // Puis on fait monter le joueur à nouveau
                i++;                                                // On incrémente i
            }
            if(deplacement() != -1){                                // Si le joueur a atteint le nb_case alors on supprime et on met une croix
                delete matrice[m_p->get_y()][m_p->get_x()];
                matrice[m_p->get_y()][m_p->get_x()] = new Croix();
                objectifAtteint();
            }
            else{
                m_s->setScoreTotal(m_s->getScoreTotal()-nb_cases*10);
                perteVie();
            }
        }

        else
            perteVie();

}
/**************************************************************
 * Nom: objectifAtteint                                       *
 **************************************************************
 * Type: void                                                 *
 **************************************************************
 * Rôle:  Fonction qui vérifie si l'objectif n'est pas atteint*
 * par le joueur.                                             *
 **************************************************************/
void GameModel::objectifAtteint()
{
    if(m_s->getDeplacement() >= m_s->getCible())
            changeLevel();
}
/************************************************************
 * Nom: changeLevel                                         *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle:  Fonction qui permet de changer de niveau, de      *
 *       demander si l'on veut continuer. Elle permet aussi *
 *       d'augmenter la valeur de l'objectif et de quitter  *
 *       si voulu.                                          *
 ************************************************************/
void GameModel::changeLevel()
{
    int reponse;
    m_n->setLevel(m_n->getLevel() + 1); // Incrémentation du level grâce à la surcharge
    m_s->setCible(m_s->getCible() + 5);
    m_n->initBonus();

    if(m_n->getLevel()%2 == 0){
        m_n->setBomb(m_n->getNb() +1);
        m_n->setBonus(m_n->getBonus() +1);
    }
    m_s->setDeplacement(0); // On remet le score déplacement à O
    
    GameView::changementLevel();
    cin >> reponse;
    if(reponse == 0){
        genereMatrice(); // Sinon on joue
    }
    else
    {
        set_answer_move("1");
        setEndGame(false); // Sinon on sort du jeu
    }
}
/************************************************************
 * Nom: deplacement                                         *
 ************************************************************
 * Type: int                                                *
 ************************************************************
 * Rôle:  Renvoie la valeur de la case où va aller le joueur*
 *      au prochain déplacement. Renvoie un integer positif *
 *      et négatif si la case suivante est occupée par une  *
 *      bombe où n'est pas contenue dans la matrice.        *
 ************************************************************/
int GameModel::deplacement(){

    string obj;
    if(m_p->get_x() >= 0 && m_p->get_x() < WIDTH_GAME && m_p->get_y() >= 0 && m_p->get_y() < HEIGHT_GAME){
         obj = matrice[m_p->get_y()][m_p->get_x()]->getObj();
    }
    else{
        return -1;
    }
    if(obj != " " && obj != "@@@" && obj != m_p->getObj() && obj != "-1-" && obj != "-2-" &&
       obj != "-3-" && obj != "-4-" && obj != "-5-" && obj != "-6-")
    {
        istringstream iss(obj);
        int nombre_cases;
        iss >> nombre_cases;
        return nombre_cases;
    }
    else if(obj == "-1-" || obj == "-2-" || obj == "-3-" ||
            obj == "-4-" || obj == "-5-" || obj == "-6-"){
        randomBonus();
        if(obj == "-1-")
            return 1;
        else if(obj == "-2-")
            return 2;
        else if(obj == "-3-")
            return 3;
        else if(obj == "-4-")
            return 4;
        else if(obj == "-5-")
            return 5;
        else
            return 6;
    }
    else
        return -1;
}
/************************************************************
 * Nom: randomBonus                                         *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle:  Fonction qui produit un chiffre aléatoire entre   *
 *      1 et 3, et affecte un type de bonus en fonction du  *
 *      chiffre tiré.                                       *
 ************************************************************/
void GameModel::randomBonus()
{
    int x = rand()%(3);

    switch(x)
    {
        case 0:
            m_n->set_bonusVie(m_n->get_b_vie() +1);
            m_p->setVie(m_p->getVie() +1);
            break;
        case 1:
            m_n->set_bonusTemps(m_n->get_b_temps() +5);
            break;
        case 2:
            m_n->set_score_bonus(m_n->get_score_bonus() +20);
            m_s->setScoreTotal(m_s->getScoreTotal()+ 20);
            break;
    }
}
/************************************************************
 * Nom: getPlayer                                           *
 ************************************************************
 * Type: const Player&  (getter)                            *
 ************************************************************
 * Rôle:  Fonction qui retourne un pointeur sur le joueur   *
 ************************************************************/
const Player& GameModel::getPlayer() const
{
    return *m_p;
}
/************************************************************
 * Nom: getScore                                            *
 ************************************************************
 * Type: const Score&  (getter)                             *
 ************************************************************
 * Rôle:  Fonction qui retourne un pointeur sur le score    *
 ************************************************************/
const Score& GameModel::getScore() const
{
    return *m_s;
}
/************************************************************
 * Nom: getLvl                                              *
 ************************************************************
 * Type: const Lvl&  (getter)                               *
 ************************************************************
 * Rôle:  Fonction qui retourne un pointeur sur le level    *
 ************************************************************/
const Lvl& GameModel::getLvl() const
{
    return *m_n;
}
/************************************************************
 * Nom: getMatrice                                          *
 ************************************************************
 * Type: Case***  (getter)                                  *
 ************************************************************
 * Rôle:  Fonction qui retourne la matrice                  *
 ************************************************************/
Case*** GameModel::getMatrice() const{

    return matrice;
}
/************************************************************
 * Nom: setMatrice                                          *
 ************************************************************
 * Type: void (setter)                                      *
 ************************************************************
 * @Param Case*** matriceBis                                *
 ************************************************************
 * Rôle:  Fonction qui retourne un pointeur sur le level    *
 ************************************************************/
void GameModel::setMatrice(Case*** matriceBis)
{
    matrice = matriceBis;
}
/************************************************************
 * Nom: genereMatrice                                       *
 ************************************************************
 * Type: void                                               *
 ************************************************************
 * Rôle:  Fonction qui génère une nouvelle matrice et       *
 *       affecte des nouvelles cases à la matrice principale*
 ************************************************************/
void GameModel::genereMatrice(){

    for (int i=0; i < 18; i++){
        for(int j=0; j < 18; j++)
            delete matrice[i][j];
    }

     for(int i=0; i<18; i++){
        for(int j=0; j<18; j++)
            matrice[i][j] = new Case();
    }

    for(int i=0; i<m_n->getNb(); i++)
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
char GameModel::saisieChoix()
{
    char choix = ' ';
    do {
        cin >> choix;
    } while(!( choix >='0' && choix <= '2'));
    
    int c = atoi(&choix);
    return c;
}
char GameModel::saisieMenu()
{
    char choix = ' ';
    do {
        cin >> choix;
    } while(!( choix >='0' && choix <= '1'));
    
    int c = atoi(&choix);
    return c;
}
int GameModel::rejouerPartie()
{
    if(get_answer_move() != "1"){ // On affiche les scores seulement si on a pas abandonné
        GameView::affichageScore();
    }
    GameView::rejouer();
    int message = saisieMenu();
    setEndGame(true);
    initLevel();
    genereMatrice();
    
    return message;
}










