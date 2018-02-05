/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.25
*	Purpose: Main file for Lab 06, EECS 268
*/

#include "Sorts.h"

void printMenu()
{
    std::cout 	<< "\n\nSelect a sort:\n"
            << "1) Bubble Sort\n"
            << "2) Insertion Sort\n"
            << "3) Selection Sort\n"
            << "4) Bogo Sort (use only with very small arrays!)\n"
            << "Enter choice: \n";
}

int* createRandomIntArray(int size, int min, int max)
{
    int* arr = new int[size];
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(min, max);

    //generate random values and put them in the array
    for(int i = 0; i < size; i++)
    {
        arr[i] = distribution(generator);
    }

    //return the array
    return arr;
}

void printArray(int arr[], int size)
{
    std::cout << "{";
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if(i != size-1)
        {
            std::cout << ",";
        }
    }
    std::cout << "}\n\n";
}

int main()
{
    //Declarations-------------------------------
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;
    char quit = 'n';
    int size, min, max, menuChoice;
    int* arr;

    //OPERATING LOOP

    while(quit == 'n')
    {
        //print the menu and record user choice
        printMenu();
        std::cin >> menuChoice;

        //capture size, min and max of the array
        std::cout << "Input a size for the random array: \n";
        std::cin >> size;

        std::cout << "Input a lower bound on the range of random numbers: \n";
        std::cin >> min;

        std::cout << "Input an upper bound on the range of random numbers: \n";
        std::cin >> max;

        //create array
        arr = createRandomIntArray(size, min, max);

        //ask if user would like to print unsorted array
        char printOrNo;
        std::cout << "Do you want to print the unsorted array? (y/n): \n";
        std::cin >> printOrNo;
        if(printOrNo == 'y')
        {
            std::cout << "Here is the unsorted array: " << std::endl;
            printArray(arr, size);
        }

        if(menuChoice == 1)
        {
            std::cout << "Sorting with bubble sort..." << std::endl;

            start = std::chrono::system_clock::now();

            Sorts<int>::bubbleSort(arr, size);

            end = std::chrono::system_clock::now();
            elapsed = (end - start);
        }
        else if(menuChoice == 2)
        {
            std::cout << "Sorting with insertion sort..." << std::endl;

            start = std::chrono::system_clock::now();

            Sorts<int>::insertionSort(arr, size);

            end = std::chrono::system_clock::now();
            elapsed = (end - start);
        }
        else if(menuChoice == 3)
        {
            std::cout << "Sorting with selection sort..." << std::endl;

            start = std::chrono::system_clock::now();

            Sorts<int>::selectionSort(arr, size);

            end = std::chrono::system_clock::now();
            elapsed = (end - start);
        }
        else if(menuChoice == 4)
        {
            std::cout << "Sorting with bogo sort..." << std::endl;

            start = std::chrono::system_clock::now();

            Sorts<int>::bogoSort(arr, size);

            end = std::chrono::system_clock::now();
            elapsed = (end - start);
        }

        //ask if user would like to print sorted array
        std::cout << "Do you want to print the sorted array? (y/n): ";
        std::cin >> printOrNo;
        if(printOrNo == 'y')
        {
            std::cout << "\nHere is the sorted array: " << std::endl;
            printArray(arr, size);
        }

        std::cout << size << " numbers were sorted in " << elapsed.count() << " seconds.\n\n";

        //ask if user would like to quit
        std::cout << "Do you want to quit? (y/n): ";
        std::cin >> quit;

        //DELETE THE ARRAY

        delete[] arr;
    }

    return 0;
}
