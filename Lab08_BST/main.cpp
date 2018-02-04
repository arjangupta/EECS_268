/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	@brief: main file for Lab08, EECS 268
*/

#include "BinarySearchTree.h"
#include <climits>
#include <random>
#include <ctime>

void printMenu()
{
    std::cout << "\nInput a selection\n"
                 "1) Add more values to original tree\n"
                 "2) Copy the original tree\n"
                 "3) Delete the original tree (one time only)\n"
                 "4) Print original tree\n"
                 "5) Print copy\n"
                 "6) Search original tree\n"
                 "7) Search copy\n"
                 "8) Exit\n"
                 "Your choice: \n";
}

int main(int argc, char** argv)
{
    BSTI<int>* myBST = new BinarySearchTree<int>();
    BSTI<int>* copyBST = nullptr;

    bool loopMenu = true;
    int menuSelection, min, max;
    min = INT_MIN;
    max = INT_MAX;

    std::cout << "\nArg count: " << argc << std::endl;

    if(argc > 1)
    {
        static std::default_random_engine generator(time(nullptr));
        static std::uniform_int_distribution<int> distribution(min, max);
        int numNodes = atoi(argv[1]);

        std::cout << "Node count: " << numNodes << "\n\n";

        //create that many numbers
        std::cout << "Filling original tree with " << numNodes << " values.\n";

        for(int i = 0; i < numNodes; i++)
        {
            int newNum = distribution(generator);
            std::cout << "Adding " <<  newNum << " to original tree\n";
            //add the random number to myBST
            myBST->add(newNum);
        }
    }
    else
    {
        std::cout << "Node count: 0 (You are working with an empty tree)" << std::endl;
    }

    while(loopMenu)
    {
        printMenu();
        std::cin >> menuSelection;
        std::cout << "You chose: " << menuSelection << std::endl;

        switch(menuSelection)
        {
            case 1:
            {
                if(myBST == nullptr)
                {
                    std::cout << "Original doesn't exist.\n";
                }
                else
                {
                    int addValue;
                    std::cout << "Input a value to add to the original: ";
                    std::cin >> addValue;
                    std::cout << "Adding " << addValue << " to the original tree. \n";
                    myBST->add(addValue);
                }
            }
            break;

            case 2:
            {
                if(myBST == nullptr)
                {
                    std::cout << "Original tree doesn't exist. Cannot copy.\n";
                }
                else
                {
                    std::cout << "Creating a copy of original tree\n";
                    if(copyBST == nullptr)
                    {
                        copyBST = myBST->clone();
                    }
                    else
                    {
                        delete copyBST;
                        copyBST = myBST->clone();
                    }
                }
            }
            break;

            case 3:
            {
                if(myBST == nullptr)
                {
                    std::cout << "Original tree has already been deleted.\n";
                }
                else
                {
                    delete myBST;
                    myBST = nullptr;
                    std::cout << "Original Tree deleted.\n";
                }
            }
            break;

            case 4:
            {
                if(myBST == nullptr)
                {
                    std::cout << "This tree doesn't exist. Cannot print.\n";
                }
                else
                {
                    int printChoice;
                    Order order;
                    std::cout << "print order options:\n"
                            << "0 - pre-order\n"
                            << "1 - in-order\n"
                            << "2 - post-order\n"
                            << "Choice: ";
                    std::cin >> printChoice;
                    std::cout << "You chose: " << printChoice << std::endl;

                    switch(printChoice)
                    {
                        case 0:
                            order = PRE_ORDER;
                            myBST->printTree(order);
                            std::cout << "\n";
                            break;

                        case 1:
                            myBST->sortedPrint();
                            std::cout << "\n";
                            break;

                        case 2:
                            order = POST_ORDER;
                            myBST->printTree(order);
                            std::cout << "\n";
                            break;

                        default:
                            std::cout << "Invalid input, try again.\n";
                    }
                }
            }
            break;

            case 5:
            {
                if(copyBST == nullptr)
                {
                    std::cout << "This tree doesn't exist. Cannot print.\n";
                }
                else
                {
                    int printChoice;
                    Order order;
                    std::cout << "print order options:\n"
                            << "0 - pre-order\n"
                            << "1 - in-order\n"
                            << "2 - post-order\n"
                            << "Choice: ";
                    std::cin >> printChoice;
                    std::cout << "You chose: " << printChoice << std::endl;

                    switch(printChoice)
                    {
                        case 0:
                            order = PRE_ORDER;
                            copyBST->printTree(order);
                            std::cout << "\n";
                            break;

                        case 1:
                            copyBST->sortedPrint();
                            std::cout << "\n";
                            break;

                        case 2:
                            order = POST_ORDER;
                            copyBST->printTree(order);
                            std::cout << "\n";
                            break;

                        default:
                            std::cout << "Invalid input, try again.\n";
                    }
                }
            }
            break;

            case 6:
            {
                if(myBST == nullptr)
                {
                    std::cout << "This tree doesn't exist. Cannot search.\n";
                }
                else
                {
                    int whatValue;
                    int foundValue = 0;
                    std::cout << "What value are you looking for?\n";
                    std::cin >> whatValue;
                    std::cout << "Searching for " << whatValue << " in the original tree...\n";
                    foundValue = myBST->search(whatValue);
                    if(foundValue == whatValue)
                    {
                        std::cout << "Found the value in the tree.\n";
                    }
                }
            }
            break;

            case 7:
            {
                if(copyBST == nullptr)
                {
                    std::cout << "This tree doesn't exist. Cannot search.\n";
                }
                else
                {
                    int whatValue;
                    int foundValue = 0;
                    std::cout << "What value are you looking for?\n";
                    std::cin >> whatValue;
                    std::cout << "Searching for " << whatValue << " in the copy tree...\n";
                    foundValue = copyBST->search(whatValue);
                    if(foundValue == whatValue)
                    {
                        std::cout << "Found the value in the tree.\n";
                    }
                }
            }
            break;

            case 8:
            {
                std::cout << "Exiting...\n\n";
                loopMenu = false;
            }
            break;

            default:
            {
                std::cout << "Invalid input. Please try again.\n";
            }
        }
    }

    if(myBST != nullptr)
    {
        delete myBST;
    }

    if(copyBST != nullptr)
    {
        delete copyBST;
    }

    return 0;
}
