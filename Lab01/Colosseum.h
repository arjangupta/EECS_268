/**
*	@file : Pokemon.h
*	@author :  Arjan Gupta
*	@date : 2015.01.28
*	Purpose: Header file of Colosseum Class for Lab01
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

class Colosseum
{
public:
    /**
    *  @pre None
    *  @post Initializes dice to appropriate sizes
    *  @return Initializes d20 to Dice(20) and d6 to Dice(6)
    */
    Colosseum();

    /**
    *  @pre calls a Pokemon object by reference
    *  @post sets the stats of the Pokemon, according to the given restrictions
    *  @return None
    */
    void userBuild(Pokemon &p);

    /**
    *  @pre calls 2 Pokemon objects by reference
    *  @post calculates attack hits, determines if attack hits, how much damage is dealt, displays attack info, determines if player died from attack
    *  @return a boolean
    */
    bool attack(const Pokemon& attacker, Pokemon& defender);

    /**
    *  @pre calls 2 Pokemon objects by reference
    *  @post handles the fight between 2 players, uses a 2 sided dice to decide who goes first, determines when the game is over
    *  @return None
    */
    void play(Pokemon& p1, Pokemon& p2);
private:
    Dice d20;
    Dice d6;
};

#endif //COLOSSEUM_H
