#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "errorcheck.h"
#include "MergeSort.h"

void Merge(int* A, int p, int q, int r);

void MergeSort(int* A, int p, int r)
{
	int q;

	if( p < r )
	{
		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

void Merge(int* A, int p, int q, int r)
{
	int *tmp1, *tmp2;
	int elements1 = q + 1 - p;
	int elements2 = r - q;
	int i, j, startidx;

	CALLOC(tmp1, elements1,sizeof(int));
	CALLOC(tmp2, elements2,sizeof(int));

	memcpy(tmp1, &A[p], elements1 * sizeof(int));
	memcpy(tmp2, &A[q + 1], elements2 * sizeof(int));

	i = 0; j = 0; startidx = p;
	while( (i < elements1) && (j < elements2) )
	{
		if(tmp1[i] > tmp2[j])
			A[startidx++] = tmp2[j++];
		else
			A[startidx++] = tmp1[i++];
	}

	while( i < elements1)
		A[startidx++] = tmp1[i++];
	while( i < elements2)
		A[startidx++] = tmp2[j++];
    
    if(PRTASK) PrintAsterisks(A);
    if(PRINTSORTING) PrintArray(A);
	FREE(tmp1);
	FREE(tmp2);
}
