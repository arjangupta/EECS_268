/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.04
*	Purpose: Main file of Lab01
*/

#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"

int main()
{

    //declare 2 Pokemon instances
    Pokemon P1;
    Pokemon P2;

    //declare a Colosseum instance
    Colosseum Colo;

    //other variables
    char playAgain = 'y';

    while(playAgain == 'y')
    {
        std::cout << std::endl;

        // ask user to build first pokemon
        std::cout << "Player 1, build your Pokemon!\n=====================" << std::endl;
        Colo.userBuild(P1);

        //ask user to build second pokemon
        std::cout << "Player 2, build your Pokemon!\n=====================" << std::endl;
        Colo.userBuild(P2);

        //Now play the game
        Colo.play(P1, P2);

        do
        {
            //ask the user if they would like to play again
            std::cout << "\nDo you want to play again? (y/n): " << std::endl;
            std:: cin >> playAgain;

        }while(playAgain != 'y' && playAgain != 'n');
    }

    std::cout << "\nThanks for playing!" << std::endl;

    return(0);
}
