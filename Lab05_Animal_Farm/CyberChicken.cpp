/**
*	@file : CyberChicken.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Implementation file for CyberChicken class, Lab 05, EECS 268
*/

#include "CyberChicken.h"

CyberChicken::CyberChicken()
{
    m_name = "Cyber Chicken";
    m_sound = "Resistance is futile";
}

int CyberChicken::getCyberEggs() const
{
    return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs)
{
    m_eggs = eggs;
}
