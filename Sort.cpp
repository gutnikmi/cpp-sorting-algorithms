#include <iostream>
#include "Sort.h"


Sorter::Sorter(Sorting *srt) : s(srt) {}

Sorter::~Sorter() { delete s; }

void Sorter::sort(int Array[], int start, int end) { s->sort( Array,  start,  end); }


void Bubble_sort::sort(int Array[], int start, int end) {
    int listLength = end - start + 1;
    while (listLength--) {
        bool swapped = false;

        for (int i = start; i < listLength; i++) {
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
}

void Selection_sort::sort(int Array[], int start, int end){
    int listLength = end - start + 1;

    for(int i = start; i < listLength; i++)
    {
        int smallestPosition = findSmallestPosition(Array, i, listLength);
        std::swap(Array[i], Array[smallestPosition]);
    }
}

void Insertion_sort::sort(int Array[], int start, int end) {
    int listLength = end - start + 1;

    for(int i = start+1; i < listLength; i++)
    {
        int j = i - 1;
        while(j >= start && Array[j] > Array[j + 1])
        {
            std::swap(Array[j], Array[j + 1]);
            j--;
        }
    }
}

int Quick_sort::partition(int Array[], int start, int pivot){
    int i = start;
    while(i < pivot)
    {
        if(Array[i] > Array[pivot] && i == pivot-1)
        {
            std::swap(Array[i], Array[pivot]);
            pivot--;
        }

        else if(Array[i] > Array[pivot])
        {
            std::swap(Array[pivot - 1], Array[pivot]);
            std::swap(Array[i], Array[pivot]);
            pivot--;
        }

        else i++;
    }
    return pivot;
}

void Quick_sort::sort (int Array[], int start, int end){
    if(start < end)
    {
        int pivot = partition(Array, start, end);

        sort(Array, start, pivot - 1);
        sort(Array, pivot + 1, end);
    }
}

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

void Shell_sort::sort(int Array[], int start, int end){
    int listLength = end + 1;
    for(int step = listLength/2; step > 0; step /= 2)
    {
        for (int i = step; i < listLength; i += 1)
        {
            int j = i;
            while(j >= step && Array[j - step] > Array[i])
            {
                std::swap(Array[j], Array[j - step]);
                j-=step;
            }
        }
    }
}

void Heap_sort::heapify(int Array[], int listLength, int root){
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;

    if (l < listLength && Array[l] > Array[largest])
        largest = l;

    if (r < listLength && Array[r] > Array[largest])
        largest = r;

    if (largest != root)
    {
        std::swap(Array[root], Array[largest]);
        heapify(Array, listLength, largest);
    }
}

void Heap_sort::sort (int Array[], int start, int end){
    int listLength = end + 1;
    for(int i = listLength / 2 - 1; i >= 0; i--)
        heapify(Array, listLength, i);

    for(int i = listLength - 1; i >= 0; i--)
    {
        std::swap(Array[0], Array[i]);
        heapify(Array, i, 0);
    }
}
