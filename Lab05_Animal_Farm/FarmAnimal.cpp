/**
*	@file : FarmAnimal.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Implementation file for FarmAnimal class, Lab 05, EECS 268
*/

#include "FarmAnimal.h"

FarmAnimal::FarmAnimal()
{
    m_name = "unset";
    m_sound = "unset";
}

std::string FarmAnimal::getName() const
{
    return m_name;
}

void FarmAnimal::setName(std::string name)
{
    m_name = name;
}

std::string FarmAnimal::getSound() const
{
    return m_sound;
}

void FarmAnimal::setSound(std::string sound)
{
    m_sound = sound;
}
