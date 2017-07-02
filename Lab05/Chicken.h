/**
*	@file : Chicken.h
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Header file for Chicken class, Lab 05, EECS 268
*/

#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"

class Chicken : public FarmAnimal
{
public:
    /**
        *  @pre None
        *  @post Initializes inherited m_name and m_sound
        *  @return Initializes m_name to "Chicken and m_sound to "Cluck"
        */
    Chicken();

protected:
    /**
        *  @pre None
        *  @post None
        *  @return the m_eggs of the Chicken
        */
    int getEggs() const;

    /**
        *  @pre an int
        *  @post sets m_eggs to the int passed in
        *  @return None
        */
    void setEggs(int eggs);

    int m_eggs;
};

#endif //CHICKEN_H
