/**
*	@file : AnimalPen.h
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Header file for AnimalPen class, Lab 05, EECS 268
*/

#ifndef ANIMAL_PEN_H
#define ANIMAL_PEN_H

#include "Stack.h"
#include "FarmAnimal.h"

class AnimalPen : public Stack<FarmAnimal*>
{
public:
    /**
        *  @pre None
        *  @post None
        *  @return None
        */
    AnimalPen();

    /**
        *  @pre None
        *  @post deletes all the animals in the stack
        *  @return None
        */
    ~AnimalPen();

    /**
        *  @pre FarmAnimal pointer
        *  @post pushes the FarmAnimal into the pen (onto the stack)
        *  @return None
        */
    void addAnimal(FarmAnimal* animal);

    /**
        *  @pre None
        *  @post None
        *  @return pointer to the next animal
        */
    FarmAnimal* peekAtNextAnimal();

    /**
        *  @pre None
        *  @post delete animal and removes from stack
        *  @return None
        */
    void releaseAnimal();

    /**
        *  @pre None
        *  @post None
        *  @return true if the pen is empty
        */
    bool isPenEmpty();
};

#endif //ANIMAL_PEN_H
