/**
*	@file : SortDriver.cpp
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Implementation file for SortDriver class, Lab07, EECS 268
*/

#include "SortDriver.h"

void SortDriver::run(int argc, char** argv)
{
    std::string sortName = argv[2];
    std::string ifileName = argv[3];
    std::string ofileName = argv[4];

    if(areParametersValid(sortName, ifileName))
    {
        double sortedTime;

        std::cout << "Calculating sort timing information..." << std::endl;

        //Declare and open input file
        std::ifstream inputFile(ifileName);
        int size = getFileCount(inputFile);
        int* arr = new int[size];

        arr = createArray(inputFile, size);

        inputFile.close();

        //Declare and open output file
        std::ofstream outputFile(ofileName);

        if(sortName == "-bubble")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
            outputFile << "Bubble Sort sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-selection")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
            outputFile << "Selection Sort sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-insertion")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
            outputFile << "Insertion Sort sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-quick")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);
            outputFile << "Quick Sort sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-quick3")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, arr, size);
            outputFile << "Quick Sort (with median) sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-merge")
        {
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);
            outputFile << "Merge Sort sorted " << size << " numbers in " << sortedTime << " seconds.";
        }
        else if(sortName == "-all")
        {
            //Declare 5 arrays and copy them from arr. Bubble sort just uses the original arr
            int* arrSelection = new int[size];
            copyArray(arr, arrSelection, size);
            int* arrInsertion = new int[size];
            copyArray(arr, arrInsertion, size);
            int* arrQuick = new int[size];
            copyArray(arr, arrQuick, size);
            int* arrQuick3 = new int[size];
            copyArray(arr, arrQuick3, size);
            int* arrMerge = new int[size];
            copyArray(arr, arrMerge, size);

            //Call sortedTime on all the sorts
            sortedTime = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
            outputFile << "Bubble Sort sorted " << size << " numbers in " << sortedTime << " seconds.\n";

            sortedTime = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arrSelection, size);
            outputFile << "Selection Sort sorted " << size << " numbers in " << sortedTime << " seconds.\n";

            sortedTime = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arrInsertion, size);
            outputFile << "Insertion Sort sorted " << size << " numbers in " << sortedTime << " seconds.\n";

            sortedTime = Sorts<int>::sortTimer(Sorts<int>::quickSort, arrQuick, size);
            outputFile << "Quick Sort sorted " << size << " numbers in " << sortedTime << " seconds.\n";

            sortedTime = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian, arrQuick3, size);
            outputFile << "Quick Sort (with Median) sorted " << size << " numbers in " << sortedTime << " seconds.\n";

            sortedTime = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arrMerge, size);
            outputFile << "Merge Sort sorted " << size << " numbers in " << sortedTime << " seconds.\n";
        }

        outputFile.close();

        std::cout << "Calculations finshed. Results stored in " << ofileName << ".\n"
                  << "Exiting...\n";
    }
    else
    {
        printHelpMenu();
    }
}

void SortDriver::printHelpMenu()
{
    std::cout << "\nSorting is done one of the following ways:\n\n"
            << "./prog -sort -bubble inputFile outputFile\n"
            << "./prog -sort -selection inputFile outputFile\n"
            << "./prog -sort -insertion inputFile outputFile\n"
            << "./prog -sort -quick inputFile outputFile\n"
            << "./prog -sort -quick3 inputFile outputFile\n"
            << "./prog -sort -merge inputFile outputFile\n"
            << "./prog -sort -all inputFile outputFile\n"
            << "Option explainations:\n"
            << "\t-bubble to time bubble sort and store all timing results in outputFile\n"
            << "\t-selection to time selection sort and store all timing results in outputFile\n"
            << "\t-insertion to time insertion sort and store all timing results in outputFile\n"
            << "\t-quick to time quick sort and store all timing results in outputFile\n"
            << "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
            << "\t-merge to time merge sort  and store all timing results in outputFile\n"
            << "\t-all to time all of the sorts and store all timing results in outputFile\n"
            << "\tinputFile must be file created by a NumberFileGenerator\n"
            << "\toutputFile must be to a valid path. It will hold the timing results\n";
}

bool SortDriver::isFileAccessible(std::string fileName)
{
    std::ifstream file(fileName);
    if(file.good())
    {
        file.close();
        return (true);
    }
    else
    {
        file.close();
        return (false);
    }
}

bool SortDriver::isSortValid(std::string sortParameter)
{
    if(sortParameter == "-bubble" || sortParameter == "-selection" || sortParameter == "-insertion" || sortParameter == "-quick" || sortParameter == "-quick3" || sortParameter == "-merge" || sortParameter == "-all")
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
    if(isFileAccessible(inputFileName) && isSortValid(sortName))
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
    int count;
    inputFile >> count;
    return (count);
}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        inputFile >> arr[i];
    }
    return arr;
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
    for(int i = 0; i < size; i++)
    {
        copy[i] = original[i];
    }
}
