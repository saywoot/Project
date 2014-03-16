#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Case.h"
#include "Const.h"

using namespace std;

Case::Case(){
    m_obj = ELEM[rand()%(NB_ELEM)];
}

void Case::add_o(string o){
    m_obj=o;
}
void Case::random_add(){
    srand((unsigned) time(NULL));
    m_obj=ELEM[rand()%(NB_ELEM)];
}
// retourne l'objet (utiliser pour la matrice)
string Case::getObj() const
{
    return m_obj;
}
// Fonction permettant l'affichage de l'objet
// retourne un string
string Case::toString() const
{
    ostringstream out;
    out<< m_obj;

    string s = out.str();
    return s;
}
// Surcharge de l'opérateur <<
ostream &operator<<(ostream &out, const Case &autre)
{
    out << autre.toString();
    return out;
}

