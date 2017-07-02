/**
*	@file : Pokemon.h
*	@author :  Arjan Gupta
*	@date : 2015.01.28
*	Purpose: Header file of Pokemon Class
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
public:
    /**
    *  @pre None
    *  @post Initializes numeric data and strings
    *  @return Initializes all numeric data to zero and strings to ""
    */
    Pokemon();

    /**
    *  @pre an int that is the amount of HP to be reduced
    *  @post Reduces m_hp by the amount
    *  @return None
    */
    void reduceHP(int amount);

    /**
    *  @pre None
    *  @post None
    *  @return the HP of the pokemon
    */
    int getHP() const;

    /**
    *  @pre an int hp to use as the HP
    *  @post asssigns the int hp as the HP of the pokemon
    *  @return None
    */
    void setHP(int hp);

    /**
    *  @pre None
    *  @post None
    *  @return the attack level of the pokemon
    */
    int getAttackLevel() const;

    /**
    *  @pre an int atklvl to set as the attack level
    *  @post sets the attack level to atklvl
    *  @return None
    */
    void setAttackLevel(int atklvl);

    /**
    *  @pre None
    *  @post None
    *  @return the defense level of the pokemon
    */
    int getDefenseLevel() const;

    /**
    *  @pre an int dflvl
    *  @post sets dflvl to as the defense level of pokemon
    *  @return None
    */
    void setDefenseLevel(int dflvl);

    /**
    *  @pre None
    *  @post None
    *  @return name of pokemon
    */
    std::string getName() const;

    /**
    *  @pre a string called name
    *  @post sets the pokemon's m_name to name
    *  @return None
    */
    void setName(std::string name);

private:
    int m_hp; //the health points of the pokemon
    int m_attackLevel; //the attack level of the pokemon
    int m_defenseLevel; //the defense level of the pokemon
    std::string m_name; //name of the pokemon
};

#endif //POKEMON_H
