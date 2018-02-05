/**
*	@file : Pokemon.h
*	@author :  Arjan Gupta
*	@date : 2015.01.28
*	Purpose: Implementation file of Pokemon Class
*/

#include "Pokemon.h"

Pokemon::Pokemon()
{
    m_hp = 0;
    m_attackLevel = 0;
    m_defenseLevel = 0;
    m_name = "";
}

void Pokemon::reduceHP(int amount)
{
    m_hp -= amount;
}

int Pokemon::getHP() const
{
    return (m_hp);
}

void Pokemon::setHP(int hp)
{
    m_hp = hp;
}

int Pokemon::getAttackLevel() const
{
    return (m_attackLevel);
}

void Pokemon::setAttackLevel(int atklvl)
{
    m_attackLevel = atklvl;
}

int Pokemon::getDefenseLevel() const
{
   return (m_defenseLevel);
}

void Pokemon::setDefenseLevel(int dflvl)
{
    m_defenseLevel = dflvl;
}

std::string Pokemon::getName() const
{
    return (m_name);
}

void Pokemon::setName(std::string name)
{
    m_name = name;
}
