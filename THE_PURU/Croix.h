#ifndef THE_PURU_Croix_h
#define THE_PURU_Croix_h

#include <iostream>
#include <string>

#include "Case.h"

class Croix : public Case{
private:
    // Position m_p;
public:
    Croix();
    
    void set_position(int x, int y);
};

#endif
