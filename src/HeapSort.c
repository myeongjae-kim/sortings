#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "errorcheck.h"
#include "HeapSort.h"

void BuildMaxHeap(int* A, int i);
void Sorting(int* A, int heapsize);
void MaxHeapify(int* A, int idx, int heapsize);

void HeapSort(int* A)
{
	BuildMaxHeap(A, A[0] / 2); // TODO remake BuildMaxHeap and Sorting. It is totally overheaded. Percolating Down을 전혀 이해하지 못했었구만.
	if(PRINTSORTING) {
		printf("Heapified.\n");
		PrintArray(A);
	}
	Sorting(A, A[0]);
}
void BuildMaxHeap(int* A, int i) // recursion is needed
{
    for (; i > 0; i--) {
        MaxHeapify(A, i, A[0]);
        if(PRTASK)
            PrintAsterisks(A);
    }
}
void Sorting(int* A, int heapsize) // TODO make sorting algorithm
{
    int maxValue = 0;
    int i;

    for (i = A[0]; i >= 2; i--) {
        maxValue = A[1];
        A[1] = A[heapsize];
        A[heapsize--] = maxValue;
        MaxHeapify(A, 1, heapsize);
        if(PRTASK)
            PrintAsterisks(A);
    }
}

void MaxHeapify(int* A, int idx, int heapsize)
{
    int LeftChild = 0;
    int RightChild = 0;
    int temp = 0;

    temp = A[idx];

    while(idx * 2 <= heapsize) // if no child, end while loop
    {
        LeftChild = idx * 2;
        RightChild = idx * 2 + 1;
        if(RightChild <= heapsize) // both children
        {
            if(A[LeftChild] > A[RightChild])
            {
                if(A[LeftChild] > temp)
                {
                    A[idx] = A[LeftChild];
                    idx = LeftChild;
                }
                else
                    break;
            }
            else
            {
                if(A[RightChild] > temp)
                {
                    A[idx] = A[RightChild];
                    idx = RightChild;
                }
                else
                    break;
            }
        }
        else // only left child
        {
            if(A[LeftChild] > temp)
            {
                A[idx] = A[LeftChild];
                idx = LeftChild;
            }
            else
                break;
        }
    }
    A[idx] = temp;
}
