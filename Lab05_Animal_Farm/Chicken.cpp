/**
*	@file : Chicken.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Implementation file for Chicken class, Lab 05, EECS 268
*/

#include "Chicken.h"

Chicken::Chicken()
{
    m_name = "Chicken";
    m_sound = "Cluck";
}

int Chicken::getEggs() const
{
    return m_eggs;
}

void Chicken::setEggs(int eggs)
{
    m_eggs = eggs;
}
