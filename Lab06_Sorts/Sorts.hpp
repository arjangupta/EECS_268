/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.03.25
*	Purpose: Template implementation file for Sorts class, Lab06, EECS 268
*/

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    while(!isSorted(arr, size))
    {
       for(int i = 0; i < size - 1; i++)
       {
           if(arr[i] > arr[i+1])
           {
               T temp = arr[i+1];
               arr[i+1] = arr[i];
               arr[i] = temp;
           }
       }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
    static std::default_random_engine generator(time(nullptr));
    while(!isSorted(arr, size))
    {
        shuffle(arr, size, generator);
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        for(int j = (i-1); j >= 0; j--)
        {
            if(arr[j] > arr[j+1])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    int minIndex = 0;
    for(int j = 0; j < size-1; j++)
    {
        minIndex = j;
        for(int i = j+1; i < size; i++)
        {
            if(arr[minIndex] > arr[i])
            {
                minIndex = i;
            }
        }
        if(minIndex != j)
        {
            T temp = arr[j];
            arr[j] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return (false);
        }
    }
    return (true);
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
    static std::uniform_int_distribution<int> distribution(0, size-1);
    int randomNumber = 0;

    for(int i = 0; i < size; i++)
    {
        randomNumber = distribution(generator);
        T temp = arr[i];
        arr[i] = arr[randomNumber];
        arr[randomNumber] = temp;
    }
}
