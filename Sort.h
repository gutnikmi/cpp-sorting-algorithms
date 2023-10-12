//
// Created by Lap_g on 11.10.2023.
//

#ifndef CPP_PROJECTS_SORT_H
#define CPP_PROJECTS_SORT_H

/*
 * An OOP based implementation
 * of a class with different sorting algorithms
 * using the Strategy pattern*/

class Sorting{
public:
    virtual ~Sorting() = default;
    virtual void sort(int A[], int p, int r) = 0;

};

class Sorter{
public:
    explicit Sorter(Sorting* srt);
    ~Sorter();
    void sort(int A[], int p, int r);
private:
    Sorting* s;

};

/** Merge sorting algorithm
* complexity in any case: O(n*log n)*/

class Merge_sort : public Sorting{
public:

    void merge(int A[],int p, int r, int q);

    void sort (int A[], int p, int r) override;
};
#endif //CPP_PROJECTS_SORT_H
