/**
*	@file : AnimalPen.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Implementation file for AnimalPen class, Lab 05, EECS 268
*/

#include "AnimalPen.h"

AnimalPen::AnimalPen()
{
    //empty
}

AnimalPen::~AnimalPen()
{
    while(!isPenEmpty())
    {
        releaseAnimal();
    }
}

void AnimalPen::addAnimal(FarmAnimal* animal)
{
    push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal()
{
    return peek();
}

void AnimalPen::releaseAnimal()
{
    delete peekAtNextAnimal();
    pop();
}

bool AnimalPen::isPenEmpty()
{
    if(isEmpty())
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
