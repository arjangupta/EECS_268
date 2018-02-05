/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.25
*	Purpose: Main class for Lab 04, EECS 268
*/

#include "Stack.h"

void printMenu()
{
    std::cout << "\n\nSelect an action:\n"
        << "1) Add something to stack 1\n"
        << "2) Add something to stack 2\n"
        << "3) See what is at the top of stack 1\n"
        << "4) See what is at the top of stack 2\n"
        << "5) Print contents in stack 1\n"
        << "6) Print contents in stack 2\n"
        << "7) Remove something from stack 1\n"
        << "8) Remove something from stack 2\n"
        << "9) Compare Stacks\n"
        << "10) Quit\n"
        << "Enter choice: \n";
}

template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
    std::cout 	<< "\nComparison of stacks:\n"
            << "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
            << "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
            << "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
            << "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
            << "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
            << "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}

int main()
{
    StackInterface<std::string>* lane1 = new Stack<std::string>();
    StackInterface<std::string>* lane2 = new Stack<std::string>();

    int menuInput = 0;

    while(menuInput != 10)
    {
        printMenu();
        std::cin >> menuInput;
        std::cout << "You chose: " << menuInput << std::endl;

        if(menuInput == 1)
        {
            std::string addStack1;
            std::cout << "What is going in stack 1?: ";
            std::cin >> addStack1;

            lane1->push(addStack1);

            std::cout << std::endl << addStack1 << " successfully added to stack 1";
        }
        else if(menuInput == 2)
        {
            std::string addStack2;
            std::cout << "What is going in stack 2?: ";
            std::cin >> addStack2;

            lane2->push(addStack2);

            std::cout << std::endl << addStack2 << " successfully added to stack 2";
        }
        else if(menuInput == 3)
        {
            std::string peekValue1;
            try
            {
                peekValue1 = lane1->peek();
                std::cout << peekValue1 << " is at the top of stack 1" << std::endl;
            }
            catch(PreconditionViolationException &p)
            {
                std::cout << p.what();
            }
        }
        else if(menuInput == 4)
        {
            std::string peekValue2;
            try
            {
                peekValue2 = lane2->peek();
                std::cout << peekValue2 << " is at the top of stack 2" << std::endl;
            }
            catch(PreconditionViolationException &p)
            {
                std::cout << p.what();
            }
        }
        else if(menuInput == 5)
        {
            lane1->print();
            std::cout << std::endl;
        }
        else if(menuInput == 6)
        {
            lane2->print();
            std::cout << std::endl;
        }
        else if(menuInput == 7)
        {
            std::string popValue1;
            try
            {
                popValue1 = lane1->pop();
                std::cout << popValue1 << " removed from stack 1" << std::endl;
            }
            catch(PreconditionViolationException &p)
            {
                std::cout << p.what();
            }
        }
        else if(menuInput == 8)
        {
            std::string popValue2;
            try
            {
                popValue2 = lane2->pop();
                std::cout << popValue2 << " removed from stack 2" << std::endl;
            }
            catch(PreconditionViolationException &p)
            {
                std::cout << p.what();
            }
        }
        else if(menuInput == 9)
        {
            compareStacks(*lane1, *lane2);
        }
        else if(menuInput == 10)
        {
            std::cout << "Program ending" << std::endl;
        }
        else
        {
            std::cout << "Invalid input, please try again." << std::endl;
        }
    }

    delete lane1;
    delete lane2;

    return (0);
}
