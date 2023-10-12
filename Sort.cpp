#include <iostream>
#include "Sort.h"


Sorter::Sorter(Sorting *srt) : s(srt) {}

Sorter::~Sorter(){delete s;}

void Sorter::sort(int A[], int p, int r){s->sort( A, p, r);}







void Merge_sort::sort(int A[], int p, int r)
{
    int q;
    if (p < r){

        q=(p+r)/2;
        sort(A, p, q);
        sort(A, q+1, r);
        merge(A,p,r,q);
    }
}

void Merge_sort::merge(int A[],int p, int r, int q)
{
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
        }
        else {
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

