/**
*	@file : FarmAnimal.h
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: Header file for FarmAnimal class, Lab 05, EECS 268
*/

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include <string>

class FarmAnimal
{
public:
    /**
        *  @pre None
        *  @post initializes m_name and m_sound;
        *  @return initializes m_name and m_sound to the string "unset"
        */
    FarmAnimal();

    /**
        *  @pre None
        *  @post None
        *  @return m_name of the FarmAnimal
        */
    std::string getName() const;

    /**
        *  @pre a string
        *  @post sets m_name to the string passed in
        *  @return None
        */
    void setName(std::string name);

    /**
        *  @pre None
        *  @post None
        *  @return m_sound string of the FarmAnimal
        */
    std::string getSound() const;

    /**
        *  @pre a string
        *  @post sets m_sound to that string
        *  @return None
        */
    void setSound(std::string sound);

protected:
    std::string m_name;
    std::string m_sound;
};

#endif //FARM_ANIMAL_H
