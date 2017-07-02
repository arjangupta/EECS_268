/**
*	@file : Sorts.h
*	@author :  Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Template header file for Sorts class (re-implemented from Lab06 and edited) Lab07, EECS 268
*/

#ifndef SORTS_H
#define SORTS_H

#include <cassert>
#include <iostream>
#include <functional>
#include <chrono>

template <typename T>
class Sorts
{
public: 
    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a quick Sort algorithm
            *  @return none
            */
    static void quickSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post part of the quickSort algorithm
            *  @return none
            */
    static void quickSortMedian(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical merge Sort algorithm
            *  @return none
            */
    static void mergeSort(T arr[], int size);

    /**
            *  @pre an array and an int for its size
            *  @post sorts the array using a typical bubble Sort algorithm
            *  @return none
            */
    static void bubbleSort(T arr[], int size);

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

    /**
            *  @pre afunction, an array and an int for its size
            *  @post times the sort
            *  @return returns the time, in seconds, the sort required to arr
            */
    static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);

private:
    /**
            *  @pre 2 arrays of whatever type and their sizes.
            *  @post merges the two arrays, part of the Merge Sort algorithm
            *  @return none
            */
    static void merge(T* a1, T* a2, int size1, int size2);

    /**
            *  @pre an array and two pointers first the first and last positions in the array
            *  @post sorts the array using a typical quick Sort algorithm
            *  @return none
            */
    static void quickSortRec(T arr[], int first, int last, bool median);

    /**
            *  @pre an array and two pointers first the first and last positions in the array
            *  @post part of the quick sort algorithm, sets a median pivot in the array
            *  @return none
            */
    static void setMedianPivot(T arr[], int first, int last);

    /**
            *  @pre an array and two pointers first the first and last positions in the array
            *  @post partitions the array into left and right. Used by quick sort
            *  @return none
            */
    static int partition(T arr[], int first, int last, bool median);
};

#include "Sorts.hpp"

#endif
