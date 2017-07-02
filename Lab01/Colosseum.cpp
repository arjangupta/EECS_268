/**
*	@file : Pokemon.h
*	@author :  Arjan Gupta
*	@date : 2015.01.28
*	Purpose: Implementation file for the Colosseum class
*/

#include "Colosseum.h"

Colosseum::Colosseum()
{
    d20 = Dice(20);
    d6 = Dice(6);
}

void Colosseum::userBuild(Pokemon &p)
{
    std::string PokeName;
    int hp, atkLvl, dfLvl;
    bool hpSet = false, atkSet = false, dfSet = false;

    //obtain pokemon's name from user
    std::cout << "Please name your pokemon: ";
    std::cin >> PokeName;

    p.setName(PokeName);

    //obtain HP from user
    std::cout << "How many hit points will it have? (1-50): ";

    do{
        std::cin >> hp;

        if(hp < 1 || hp > 50)
        {
            std::cout << "Sorry. The attack level must be between 1 and 50: ";
        }
        else
        {
            hpSet = true;
        }

    }while(!hpSet);

    p.setHP(hp);

    //obtain attack and defense levels
    std::cout << "Split fifty points between attack level and defense level." << std::endl;

    //first get the attack level
    std::cout << "Enter your attack level (1-49): ";

    do
    {
        std::cin >> atkLvl;

        if(atkLvl < 1 || atkLvl > 49)
        {
            std::cout << "Sorry. The attack level must be between 1 and 49: ";
        }
        else
        {
            atkSet = true;
        }

    }while(!atkSet);

    p.setAttackLevel(atkLvl);

    //now obtain the defense level
    std::cout << "Enter your defense level (1-" << (50-atkLvl) << "): ";

    do
    {
        std::cin >> dfLvl;

        if(dfLvl < 1 || dfLvl > (50-atkLvl))
        {
            std::cout << "Sorry. The defense level must be between 1 and " << (50-atkLvl) << ": ";
        }
        else
        {
            dfSet = true;
        }

    }while(!dfSet);

    p.setDefenseLevel(dfLvl);

}

bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{
    int attackBonus, defenseBonus, roll1, roll2, roll3, totalDamage;

    //ATTACKER ATTACKS THE DEFENDER

    std::cout << attacker.getName() << " is attacking " << defender.getName() << std::endl;

    attackBonus = d20.roll();
    std::cout << attacker.getName() << " rolls an attack bonus of " << attackBonus << std::endl;

    defenseBonus = d20.roll();
    std::cout << defender.getName() << " rolls an defense bonus of " << defenseBonus << std::endl;

    if((attacker.getAttackLevel() + attackBonus) > (defender.getDefenseLevel() + defenseBonus))
    {
        std::cout << "The attack hits dealing 3-D6 damage!" << std::endl;

        //roll six-sided dice 2 times.
        roll1 = d6.roll();
        roll2 = d6.roll();
        roll3 = d6.roll();
        totalDamage = roll1 + roll2 + roll3;
        std::cout << "The rolls are " << roll1 << ", " << roll2 << ", and " << roll3 << " totaling: " << totalDamage << " damage!" << std::endl;

        //defender takes the hit
        defender.reduceHP(totalDamage);

        if(defender.getHP() <= 0)
        {
            std::cout << defender.getName() << " have been defeated!" << std::endl;
            return(true);
        }
        else
        {
            std::cout << defender.getName() << " has " << defender.getHP() << " hit points left." << std::endl;
            return(false);
        }
    }
    else
    {
        std::cout << "The attack missed!" << std::endl;
    }

}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
    //declare variables for round-keeping
    int roundnumber = 1;
    bool exitloop = false;

    //declare a 2 sided dice
    Dice d2 = Dice(2);

    std::cout << "\nChoosing which player to go first:" << std::endl;

    //roll the 2 sided die
    int roll = d2.roll();

    if(roll = 1){
        std::cout << "Player 1 will go first." << std::endl;

        while(!exitloop && roundnumber < 11)
        {
            std::cout << "\nRound " << roundnumber << "!\n" << std::endl;

            exitloop = attack(p1, p2);

            if(!exitloop)
            {
                exitloop = attack(p2, p1);
            }

            roundnumber++;
        }

    }
    else
    {
        std::cout << "Player 2 will go first" << std::endl;

        while(!exitloop && roundnumber < 11)
        {
            std::cout << "\nRound " << roundnumber << "!\n" << std::endl;

            exitloop = attack(p2, p1);

            if(!exitloop)
            {
                exitloop = attack(p1, p2);
            }

            roundnumber++;
        }

    }

    //if the loop was exited because of the rounds exceeding 10, then that means both players are still standing.
    //In this case, the boolean exitloop will be false. Declare a draw.

    if(!exitloop)
    {
        std::cout << std::endl << "Both fighters are still standing! It's a draw!" << std::endl;
    }

}
