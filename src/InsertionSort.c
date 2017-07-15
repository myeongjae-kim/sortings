#include <stdio.h>
#include "main.h"
#include "errorcheck.h"
#include "InsertionSort.h"

void InsertionSort(int* A)
{	
	int i, j, key;
	if(PRINTSORTING) {
		printf("before sorting.\n");
		PrintArray(A);
	}

	for (j = 2; j <= A[0]; ++j)
	{
		key = A[j];
		if(PRINTSORTING) {
			printf("Selected: A[%d](value: %d).\n", j, A[j]);
			printf("If there is a value which is bigger than selected one, Replacing!!\n");
		}
		for (i = j - 1; i > 0 && A[i] > key ; --i)
		{
			A[i + 1] = A[i];
		}
		A[i + 1] = key;
        if(PRTASK) PrintAsterisks(A);
		if(PRINTSORTING) PrintArray(A);
	}
}
