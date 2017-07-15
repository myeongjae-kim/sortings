#include <stdio.h>

#include "main.h"
#include "errorcheck.h"
#include "QuickSort.h"

int Partition(int* A, int p, int r);
void median(int *A, int p, int q, int r);

void QuickSort(int* A, int p, int r)
{ 
	int q;

	if(r <= 1 || p >= r) return; //base case

	q = Partition(A, p, r);
	QuickSort(A, p, q - 1);
	QuickSort(A, q + 1, r);
}

int Partition(int* A, int p, int r)
{ /* Median 3 */
	int q;
	int part1 = p, part2 = p;

	q = (p + r) / 2;
	median(A, p, q, r); // median value is in A[r]
    if (PRINTSORTING) {
        printf("median value is in the end of array");
        PrintArray(A);
    }

	while ( part2 < r )
	{
		if (A[part2] < A[r] ) {
			swap(&A[part1], &A[part2]);
			part1++; part2++;
            if(PRTASK) PrintAsterisks(A);
            if (PRINTSORTING) {
                printf("value which is smaller than pivot is moved to left.");
                PrintArray(A);
            }
		}
		else part2++;
	}
	swap(&A[part1], &A[r]); // A[r] will be right position.
    if (PRINTSORTING) {
        printf("pivot is right position.");
        PrintArray(A);
    }
	return q = part1;
}

void median(int *A, int p, int q, int r)
{
	/* bubble sort, descending. A[q] is median value. */
	if( A[p] < A[q]) swap(&A[p], &A[q]);
	if( A[p] < A[r]) swap(&A[p], &A[r]);
	if( A[q] < A[r]) swap(&A[q], &A[r]);
    
    /* median value is in A[r] */
    swap(&A[q], &A[r]);
}
