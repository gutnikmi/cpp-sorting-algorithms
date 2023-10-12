//
// Created by Lap_g on 11.10.2023.
//

#ifndef CPP_PROJECTS_SORT_H
#define CPP_PROJECTS_SORT_H

#include <array>

/*
 * An OOP based implementation
 * of a class with different sorting algorithms
 * using the Strategy pattern*/

class Sorting {
public:
    virtual ~Sorting() = default;

    virtual void sort(int Array[], int start, int end) = 0;

};

class Sorter {
public:
    explicit Sorter(Sorting *srt);

    ~Sorter();

    void sort(int Array[], int start, int end);

private:
    Sorting *s;

};

/** Bubble sorting algorithm
 * complexity in best case: O(n)
 * complexity on average: O(n^2)
 * complexity in worst case: O(n^2)
 * */

class Bubble_sort : public Sorting {
public:
    void sort(int Array[], int start, int end) override;
};

/** Selection sorting algorithm
 complexity in any case: O(n^2)
 * */

class Selection_sort : public Sorting {
public:
    int findSmallestPosition(const int Array[], int start, int end);
    void sort(int Array[], int start, int end) override;
};

/** Insertion sorting algorithm
 * complexity in best case: O(n)
 * complexity in worst case: O(n^2)
 * */

class Insertion_sort : public Sorting {
public:
    void sort(int Array[], int start, int end) override;
};

/** Quick sort sorting algorithm
 * complexity in best case: O(n*logn)
 * complexity in worst case: O(n^2)
 * */



/** Merge sorting algorithm
* complexity in any case: O(n*log n)*/

class Merge_sort : public Sorting {
public:

    void merge(int A[], int p, int r, int q);

    void sort(int A[], int p, int r) override;
};


#endif //CPP_PROJECTS_SORT_H
