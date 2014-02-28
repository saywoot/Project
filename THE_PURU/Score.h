//
//  Score.h
//  THE_PURU
//
//  Created by Etienne on 27/02/2014.
//  Copyright (c) 2014 sayw00t. All rights reserved.
//

#ifndef THE_PURU_Score_h
#define THE_PURU_Score_h

class Score
{
public:
    Score();
    void setDeplacement(int deplacement);
    int getDeplacement() const;
    
private:
    int nb_deplacement;
    int cpt_bonnus;
};

#endif
