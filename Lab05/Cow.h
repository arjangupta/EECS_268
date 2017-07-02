/**
*	@file : Cow.h
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Header file for Cow class, Lab 05, EECS 268
*/

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow : public FarmAnimal
{
public:
    /**
        *  @pre None
        *  @post initializes m_name and m_sound
        *  @return initializes m_name to "cow and m_sound to "Moo"
        */
    Cow();

    /**
        *  @pre None
        *  @post None
        *  @return the m_milkProduced of the Cow
        */
    double getMilkProduced() const;

    /**
        *  @pre a double
        *  @post sets m_milkProduced to the double
        *  @return None
        */
    void setMilkProduced(double gallons);

protected:
    double m_milkProduced;
};

#endif //COW_H
