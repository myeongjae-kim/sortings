#include <stdio.h>

#include "main.h"
#include "errorcheck.h"
#include "BubbleSort.h"

void BubbleSort(int* A)
{
	int i, j;
	if(PRINTSORTING) {
		printf("before sorting.\n");
		PrintArray(A);
	}


	for ( i = 1; i <= A[0] - 1; ++i)
	{
		if(PRINTSORTING) printf("Selected: A[%d](value: %d).\n", i, A[i]);
		for (j = i + 1; j <= A[0]; ++j)
		{
			if(A[i] > A[j])
            {
                if(PRINTSORTING) printf("A[%d] > A[%d]. So change A[%d] and A[%d].\n", i, j, i, j );
                swap(&A[i], &A[j]);
                if(PRINTSORTING) PrintArray(A);
            }
		}
        if(PRTASK) PrintAsterisks(A);
	}
}
