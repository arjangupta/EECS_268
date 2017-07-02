/**
*	@file : CyberChicken.h
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Header file for CyberChicken class, Lab 05, EECS 268
*/

#ifndef CYBER_CHICKEN_H
#define CYBER_CHICKEN_H

#include "Chicken.h"

class CyberChicken : public Chicken
{
public:
    /**
        *  @pre None
        *  @post initializes m_name and m_sound
        *  @return initializes m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
        */
    CyberChicken();

    /**
        *  @pre None
        *  @post None
        *  @return inherited member variable, m_eggs
        */
    int getCyberEggs() const;

    /**
        *  @pre an int
        *  @post sets the inherited variable, m_eggs
        *  @return None
        */
    void setCyberEggs(int eggs);
};

#endif //CYBER_CHICKEN_H
