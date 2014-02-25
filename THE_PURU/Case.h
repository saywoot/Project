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

class Case {
protected:
    std::string m_obj;
public:
    Case();
    void add_o(std::string o);
    void random_add();
};

#endif /* defined(__THE_PURU__Case__) */
