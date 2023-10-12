#include<iostream>
#include"Sort.h"

int main(){
    int A[8]={5,2,4,6,1,3,2,6};
    int length = (sizeof(A)/sizeof(*A));
    std::cout<<"Input array ...\n";
    for (int i: A)
        std::cout << i << " ";

    auto * s = new Sorter(new Merge_sort);
    s->sort(A, 0, length-1);
    std::cout<<"\n\nSorted array ... \n";
    for (int i : A)
        std::cout << i << " ";

    return 0;
}