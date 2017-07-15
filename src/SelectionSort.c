#include <stdio.h>
#include "main.h"
#include "errorcheck.h"
#include "SelectionSort.h"

void SelectionSort(int* A)
{
	int i, j, minidx;
	if(PRINTSORTING) {
		printf("before sorting.\n");
		PrintArray(A);
	}

	for (i = 1; i <= A[0] - 1; ++i)
	{
		minidx = i;
		for (j = i + 1 ; j <= A[0] ; ++j)
		{
			minidx = A[minidx] < A[j] ? minidx : j;
		}
		if(PRINTSORTING) printf("Selected: A[%d](value: %d).\n", i, A[i]);

		if( A[i] != A[minidx])
		{
			if(PRINTSORTING) printf("Changed: A[%d](value: %d, which is minimum).\n", minidx, A[minidx]);
			swap(&A[i], &A[minidx]);
            if(PRTASK) PrintAsterisks(A);
		}
		else
			if(PRINTSORTING) printf("Nothing Changed.\n");
		if(PRINTSORTING) PrintArray(A);
	}

}
