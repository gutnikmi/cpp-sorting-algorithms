#include <iostream>
#include "Sort.h"


Sorter::Sorter(Sorting *srt) : s(srt) {}

Sorter::~Sorter() { delete s; }

void Sorter::sort(int Array[], int start, int end) { s->sort( Array,  start,  end); }


void Bubble_sort::sort(int Array[], int start, int end) {
    int listLength = end + 1;
    while (listLength--) {
        bool swapped = false;

        for (int i = 0; i < listLength; i++) {
            if (Array[i] > Array[i + 1]) {
                std::swap(Array[i], Array[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}


int Selection_sort:: findSmallestPosition(const int Array[], int start, int end){
    int smallestPosition = start;
    int listLength = end;

    for(int i = start; i < listLength; i++)
    {
        if(Array[i] < Array[smallestPosition])
            smallestPosition = i;
    }
    return smallestPosition;
};

void Selection_sort::sort(int Array[], int start, int end){
    int listLength = end + 1;

    for(int i = 0; i < listLength; i++)
    {
        int smallestPosition = findSmallestPosition(Array, i, listLength);
        std::swap(Array[i], Array[smallestPosition]);
    }
};

void Insertion_sort::sort(int Array[], int start, int end) {
    int listLength = end + 1;

    for(int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while(j >= 0 && Array[j] > Array[j + 1])
        {
            std::swap(Array[j], Array[j + 1]);
            j--;
        }
    }
};

void Merge_sort::sort(int A[], int p, int r) {
    int q;
    if (p < r) {

        q = (p + r) / 2;
        sort(A, p, q);
        sort(A, q + 1, r);
        merge(A, p, r, q);
    }
}

void Merge_sort::merge(int A[], int p, int r, int q) {
    int mergedList[8];
    int i, j, k;
    i = p;
    k = p;
    j = q + 1;

    while (i <= q && j <= r) {
        if (A[i] < A[j]) {
            mergedList[k] = A[i];
            k++;
            i++;
        } else {
            mergedList[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= q) {
        mergedList[k] = A[i];
        k++;
        i++;
    }

    while (j <= r) {
        mergedList[k] = A[j];
        k++;
        j++;
    }

    for (i = p; i < k; i++) {
        A[i] = mergedList[i];
    }
}

