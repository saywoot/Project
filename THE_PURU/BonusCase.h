#ifndef BONUSCASE_H_INCLUDED
#define BONUSCASE_H_INCLUDED

#include <iostream>
#include <string>

#include "Case.h"

class BonusCase : public Case{

private:
    // Position m_p;
public:
    BonusCase();

    void set_position(int x, int y);
};

#endif // BONUSCASE_H_INCLUDED
