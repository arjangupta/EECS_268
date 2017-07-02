/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.25
*	Purpose: Template header file for Sorts class, Lab06, EECS 268
*/

#ifndef SORTS_H
#define SORTS_H

#include <cassert>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>

template <typename T>
class Sorts
{
public:
    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical bubble Sort algorithm
            *  @return none
            */
    static void bubbleSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical bogo Sort algorithm
            *  @return none
            */
    static void bogoSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical insertion Sort algorithm
            *  @return none
            */
    static void insertionSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical selection Sort algorithm
            *  @return none
            */
    static void selectionSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post checks if arr is in ascending order
            *  @return true if arr is in ascending order, false otherwise
            */
    static bool isSorted(T arr[], int size);

private:
    /**
            *  @pre an array and an int for its size
            *  @post For each index in the array, swap it the value at another random index
            *  @return none
            */
    static void shuffle(T arr[], int size, std::default_random_engine& generator);
};

#include "Sorts.hpp"

#endif
