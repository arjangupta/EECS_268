/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.04
*	Purpose: main file for Lab 05, EECS 268
*/

#include "AnimalPen.h"
#include "CyberChicken.h"
#include "Cow.h"

void goodbyeMessage(const FarmAnimal& animal)
{
    std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "." << std::endl;
}

void printMenu()
{
    std::cout   << "\n\nSelect an animal to add to the pen:\n"
                << "1.) Cow (produces milk)\n"
                << "2.) Chicken (cannot lay eggs)\n"
                << "3.) Cyber Chicken (seems dangerous, but lays eggs)\n"
                << "---------------------------------------------------\n"
                << "choice: ";
}

int main()
{
    AnimalPen* myPen = new AnimalPen();
    char doneAdding = 'n';
    int menuChoice = 0, totalEggs = 0;
    double totalMilkProduced = 0.0;

    while(doneAdding == 'n')
    {
        printMenu();
        std::cin >> menuChoice;

        if(menuChoice == 1)
        {
            /* ADD A COW:
             * 1. Create a Cow on the heap
             * 2. Push this Cow onto myPen
             * 3. Ask user how many gallons of milk produced, pass this double into Cow instance
             * 4. Add to the total gallons produced
             */
            double bovineMilk;
            Cow* bovine = new Cow();
            myPen->addAnimal(bovine);
            std::cout << "How many gallons of milk did this cow produce?: ";
            std::cin >> bovineMilk;
            bovine->setMilkProduced(bovineMilk);
            totalMilkProduced += bovineMilk;
        }
        else if(menuChoice == 2)
        {
            /* ADD A CHICKEN:
             * 1. Display message as shown in sample run
             * 2. Create a Chicken on the heap
             * 3. Push this Chicken onto myPen
             */
            std::cout << "Add an eggless chicken to the pen? OK. You're the boss." << std::endl;
            Chicken* hen = new Chicken();
            myPen->addAnimal(hen);
        }
        else if(menuChoice == 3)
        {
            /* ADD a CYBER CHICKEN:
             * 1. Create a CyberChicken on the heap
             * 2. Push it onto myPen
             * 3. Ask user how many eggs produced, pass this double into your CyberChicken instance
             * 4. Add to the total eggs produced
             */
            int robotEggs;
            CyberChicken* robotHen = new CyberChicken();
            myPen->addAnimal(robotHen);
            std::cout << "How many eggs did this cyber chicken produce?: ";
            std::cin >> robotEggs;
            robotHen->setCyberEggs(robotEggs);
            totalEggs += robotEggs;
        }
        else
        {
            std::cout << "Invalid input. No animals added." << std::endl;
        }

        std::cout << "Done adding animals? (y/n): ";
        std::cin >> doneAdding;

    }

    std::cout << "\nReleasing all animals!\n"
              << "-------------------------\n";

    while(!myPen->isPenEmpty())
    {
        FarmAnimal* topOfStack = myPen->peekAtNextAnimal();
        if(topOfStack->getName() == "Cow")
        {
            std::cout << "This cow produced " << (static_cast<Cow*> (topOfStack))->getMilkProduced() << " gallons of milk" << std::endl;
            goodbyeMessage(*topOfStack);
        }
        else if(topOfStack->getName() == "Chicken")
        {
            std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help?" << std::endl;
            goodbyeMessage(*topOfStack);
            std::cout << "Chicken Destructor called" << std::endl;
        }
        else if(topOfStack->getName() == "Cyber Chicken")
        {
            std::cout << "This Cyber Chicken laid " << (static_cast<CyberChicken*> (topOfStack))->getCyberEggs() << " cyber eggs. Humanity is in trouble." << std::endl;
            goodbyeMessage(*topOfStack);
            std::cout << "CyberChicken Destructor called\n"
                      << "Chicken Destructor called\n";
        }

        myPen->releaseAnimal();
    }

    std::cout << "Your farm produced " << totalMilkProduced << " gallons of milk and " << totalEggs << " eggs." << std::endl;

    delete myPen;

    return 0;
}
