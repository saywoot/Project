//
//  Case.h
//  THE_PURU
//
//  Created by sayw00t on 24/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef __THE_PURU__Case__
#define __THE_PURU__Case__

#include <iostream>
#include <string>
#include "Position.h"

class Case : public Position{ // Case hérite de Position puisque toutes cases (Player, Bomb ou case avec un chiffre à une position dans la matrice

protected:
    std::string m_obj;

public:
    Case();
    void add_o(std::string o);
    std::string getObj() const;  // retourne l'objet
    std::string toString() const;
};

std::ostream &operator<<(std::ostream &out, const Case &autre);

#endif /* defined(__THE_PURU__Case__) */
