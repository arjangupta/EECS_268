/**
*	@file : Cow.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Implementation file for Cow class, Lab 05, EECS 268
*/

#include "Cow.h"

Cow::Cow()
{
    m_name = "Cow";
    m_sound = "Moo";
}

double Cow::getMilkProduced() const
{
    return (m_milkProduced);
}

void Cow::setMilkProduced(double gallons)
{
    if(gallons > 0)
    {
        m_milkProduced = gallons;
    }
    else
    {
        m_milkProduced = 0;
    }
}
