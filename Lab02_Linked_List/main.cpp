/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.09
*	Purpose: Main file of Lab02
*/

#include <iostream>
#include "LinkedList.h"

void printMenu();

int main()
{
    //declarations
    int menuChoice = 0;
    LinkedList* myLinkedList = new LinkedList();

    while(menuChoice != 7)
    {
        printMenu(); //print the menu to the user
        std::cin >> menuChoice;

        std::cout << "You chose: " << menuChoice << std::endl;

        if(menuChoice == 1)
        {
            int userValue = 0;

            //ask for a value to add
            std::cout << "Input a value to add: ";
            std::cin >> userValue;

            std::cout << "Adding " << userValue << " to the list" << std::endl;

            myLinkedList->addFront(userValue); //actually added the value to the list

        }
        else if(menuChoice == 2)
        {
            int userValue = 0;

            //ask for a value to add
            std::cout << "Input a value to add: ";
            std::cin >> userValue;

            std::cout << "Adding " << userValue << " to the list" << std::endl;

            myLinkedList->addBack(userValue); //actually added the value to the list

        }
        else if(menuChoice == 3)
        {
            std::cout << "Attempting removal from front of list." << std::endl;

            if(myLinkedList->removeFront())
            {
                std::cout << "Removal successful." << std::endl;
            }
            else
            {
                std::cout << "There are no values to remove." << std::endl;
            }
        }
        else if(menuChoice == 4)
        {
            std::cout << "Attempting removal from back of list." << std::endl;

            if(myLinkedList->removeBack())
            {
                std::cout << "Removal successful." << std::endl;
            }
            else
            {
                std::cout << "There are no values to remove." << std::endl;
            }
        }
        else if(menuChoice == 5)
        {
            std::cout << "Printing list:" << std::endl;
            myLinkedList->printList();
        }
        else if(menuChoice == 6)
        {
            int userSearch = 0;

            //ask for a value to search for
            std::cout << "Enter a value to search for: ";
            std::cin >> userSearch;

            std::cout << "Searching for " << userSearch << "..." << std::endl;

            if(myLinkedList->search(userSearch))
            {
                std::cout << userSearch << " is in the list." << std::endl;
            }
            else
            {
                std::cout << userSearch << " is not in the list." << std::endl;
            }
        }
        else if(menuChoice == 7)
        {
            std::cout << "Exiting..." << std::endl;
        }
        else
        {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    delete myLinkedList;

    return (0);
}

void printMenu()
{
    std::cout << "\n\nSelect from the following menu:\n"
            << "1) Add to the front of the list\n"
            << "2) Add to the end of the list\n"
            << "3) Remove from front of the list\n"
            << "4) Remove from back of the list\n"
            << "5) Print the list\n"
            << "6) Search for value\n"
            << "7) Exit\n"
            << "Enter your choice: ";
}
