/**
*	@file : Sorts.hpp
*	@author :  Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Template implementation file for Sorts class (re-implemented from Lab06 and edited) Lab07, EECS 268
*/

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    quickSortRec(arr, 0, (size-1), false);
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::quickSortMedian(T arr[], int size)
{
    quickSortRec(arr, 0, (size-1), true);
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    if(size <= 1)
    {
        return;
    }
    else
    {
        int leftSize = size/2;
        int rightSize = (size - leftSize);
        T* right = (arr + size/2);
        mergeSort(arr, leftSize);
        mergeSort(right, rightSize);
        merge(arr, right, leftSize, rightSize);
    }
    assert(Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    while(!isSorted(arr, size))
    {
       for(int i = 0; i < size-1; i++)
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
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    std::chrono::duration<double> elapsed;
    start = std::chrono::system_clock::now();
    sort(arr, size);
    end = std::chrono::system_clock::now();
    assert( Sorts<T>::isSorted(arr, size));
    elapsed = (end - start);
    return (elapsed.count());
}

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
    T* tempArr = new T[size1 + size2];
    int a1count = 0;
    int a2count = 0;

    //FILL UP THE TEMP ARRAY IN A SORTED WAY

    for(int i = 0; i < (size1 + size2); i++)
    {
        if(a1count != size1 && a2count != size2)
        {
            if(a1[a1count] <= a2[a2count])
            {
                tempArr[i] = a1[a1count];
                a1count++;
            }
            else if(a2[a2count] < a1[a1count])
            {
                tempArr[i] = a2[a2count];
                a2count++;
            }
        }
        else if(a1count == size1 && a2count != size2)
        {
            tempArr[i] = a2[a2count];
            a2count++;
        }
        else if(a2count == size2 && a1count != size1)
        {
            tempArr[i] = a1[a1count];
            a1count++;
        }
    }

    //PUT ALL VALUES OF THE TEMP ARRAY IN OUR INITIAL ARRAY

    for(int i = 0; i < (size1+size2); i++)
    {
        a1[i] = tempArr[i];
    }

    //DELETE THE TEMP ARRAY

    delete[] tempArr;
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
    if(first < last)
    {
        int finalSortedIndex = partition(arr, first, last, median);
        quickSortRec(arr, first, (finalSortedIndex - 1), median);
        quickSortRec(arr, (finalSortedIndex + 1), last, median);
    }
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    int middle = (first + (last-first)/2);
    int median;

    if( ( (first >= middle) && (middle >= last) ) || ( (last >= middle) && (middle >= first) ) )
    {
        median = middle;
    }
    else if( ( (last >= first) && (first >= middle) ) || ( (middle >= first) && (first >= last) ) )
    {
        median = first;
    }
    else
    {
        median = last;
    }

    //SWAP THE MEDIAN VALUE WITH THE LAST VALUE
    T temp = arr[last];
    arr[last] = arr[median];
    arr[median] = temp;
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    if(median)
    {
        setMedianPivot(arr, first, last);
    }

    //Pick the last value in the array as the pivot
    int pivotIndex = last;
    for(int i = first; i < last; i++)
    {
        if(arr[i] >= arr[pivotIndex])
        {
            for(int j = (last-1); j >= i; j--)
            {
                if(i == j)
                {
                    //IF THE LEFT AND RIGHT VALUES HAVE MET, THEN:
                    //That meeting point value must be larger than the pivot
                    //Hence, we swap the meeting value with the pivot
                    int temp = arr[i];
                    arr[i] = arr[pivotIndex];
                    arr[pivotIndex] = temp;
                    return (i);
                }
                else if(arr[j] < arr[pivotIndex])
                {
                    //SWAP THE LEFT AND RIGHT VALUES
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;

                    //CUT THE INNER LOOP
                    j = i - 1;
                }
            }
        }
    }
    return (pivotIndex);
}
