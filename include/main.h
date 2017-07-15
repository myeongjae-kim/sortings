#ifndef MAIN_H
#define MAIN_H

#define PRINTSORTING    0 // 1 : Print list while sorting. 0: not.
#define PRTASK          1 // 1 : Print Asterisks Animation. 0: not.
#define RECTNOTASK      1 // 1 : Print Rectangle, not Asterisks.
#define SORTS           6

int* MakeRandomArray(int n);
void DestroyRandomArray(int* A);
void PrintArray(int* A);
int PrintMenu(void);

typedef void (*SelectFunction)(int *A);

void ISort(int *A);
void SSort(int *A);
void BSort(int *A);
void HSort(int *A);
void MSort(int *A);
void QSort(int *A);

void swap(int* a, int* b);

void PrintAsterisks(int *A);

#endif
