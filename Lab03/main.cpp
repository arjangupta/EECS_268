/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.20
*	Purpose: Main file for Lab03, EECS 268
*/

#include "DoubleLinkedList.h"

void printMenu()
{
    std::cout << 	"\n\nMake choice\n"
        <<	"1) push value onto front\n"
        <<	"2) push value onto back\n"
        <<	"3) insert behind a value\n"
        <<	"4) insert ahead of a value\n"
        <<	"5) remove value\n"
        <<	"6) print list\n"
        <<	"7) Quit\n"
        << 	"Your choice: ";
}

int main()
{
    DoubleLinkedList<int>* myList = new DoubleLinkedList<int>();
    int menuInput = 0;

    while(menuInput != 7)
    {
        printMenu();

        std::cin >> menuInput;
        std::cout << "You chose : " << menuInput << std::endl;

        if(menuInput == 1)
        {
            int pushValue;

            std::cout << "Give a value." << std::endl;
            std:: cin >> pushValue;

            myList->pushFront(pushValue);

            std::cout << pushValue << " added to front of list." << std::endl;
        }
        else if(menuInput == 2)
        {
            int pushValue;

            std::cout << "Give a value." << std::endl;
            std:: cin >> pushValue;

            myList->pushBack(pushValue);

            std::cout << pushValue << " added to back of list." << std::endl;
        }
        else if(menuInput == 3)
        {
            int insertValue;
            int indexValue;

            std::cout << "Give a value to insert." << std::endl;
            std::cin >> insertValue;

            std::cout << "Pick a value to insert behind." << std::endl;
            std::cin >> indexValue;

            std::cout << "Attempting to insert " << insertValue << " behind " << indexValue << std::endl << std::endl;

            try
            {
                myList->insertBehind(indexValue,insertValue);
                std::cout << insertValue << " inserted behind " << indexValue << std::endl;
            }
            catch(std::runtime_error& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if(menuInput == 4)
        {
            int insertValue;
            int indexValue;

            std::cout << "Give a value to insert." << std::endl;
            std::cin >> insertValue;

            std::cout << "Pick a value to insert ahead of." << std::endl;
            std::cin >> indexValue;

            std::cout << "Attempting to insert " << insertValue << " ahead of " << indexValue << std::endl << std::endl;

            try
            {
                myList->insertAhead(indexValue,insertValue);
                std::cout << insertValue << " inserted ahead of " << indexValue << std::endl;
            }
            catch(std::runtime_error& e)
            {
                std::cout << e.what() << std::endl;
            }

        }
        else if(menuInput == 5)
        {
            int removeValue;

            std::cout << "Give a value to remove." << std::endl;
            std::cin >> removeValue;
            std::cout << "You gave " << removeValue << std::endl << std::endl;

            if(myList->remove(removeValue))
            {
                std::cout << removeValue << " removed from the list." << std::endl;
            }
            else
            {
                std::cout << removeValue << " could not be removed from list." << std::endl;
            }
        }
        else if(menuInput == 6)
        {
            myList->printList();
        }
        else if(menuInput == 7)
        {
            std::cout << "\nProgram ending...\n\n";
        }
        else
        {
            std::cout << "\nInvalid input, please try again." << std::endl;
        }
    }

    delete myList;

    return 0;
}
