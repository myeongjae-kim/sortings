#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "errorcheck.h"

#include "InsertionSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

int main(void)
{
    int n, *A = NULL, funcNum;
    char repeat;
    SelectFunction *F = NULL;

    char* funcName[7] = {"", "Insertion Sort", "Selection Sort", "Bubble Sort", "Heap Sort", "Merge Sort", "Qucik Sort"};

    /* function pointer to select sorting method */
    MALLOC(F, (SORTS + 1) *sizeof(SelectFunction));
    F[1] = ISort;
    F[2] = SSort;
    F[3] = BSort;
    F[4] = HSort;
    F[5] = MSort;
    F[6] = QSort;
    /* */

    do{
        printf("Input Quantity of Data: ");
        scanf("%10d", &n); // scanf의 보안결함 때문에 입력수 제한 설정. 10의 자리 숫자까지.
        rewind(stdin);

        funcNum = PrintMenu();
        A = MakeRandomArray(n);

        printf(ANSI_COLOR_GREEN"\n\n\t\tYou have selected "ANSI_COLOR_YELLOW"%s"ANSI_COLOR_GREEN".\n\t\t\t   Wait...\n\n\n"ANSI_COLOR_RESET, funcName[funcNum]);
        F[funcNum](A);

        DestroyRandomArray(A);
        printf("Repeat? (y/n): "); repeat = getchar();
    }
    while( (repeat != 'N') && (repeat != 'n') );

    FREE(F);
    return 0;
}


int* MakeRandomArray(int n)
{
    int *A = NULL;
    int *tempAry = NULL;
    int randIdx = 0;
    int i = 0;

    CALLOC(A, n + 1,sizeof(int));
    A[0] = n;

    /* non-duplicated random array, fast */
    CALLOC(tempAry, n + 1,sizeof(int));

    tempAry[0] = n;
    for (i = 1; i <= n; ++i)
    {
        tempAry[i] = i;
    }

    srand(time(NULL));
    for (i = 1; i <= n && tempAry[0] > 0; ++i)
    {
        randIdx = (rand() % tempAry[0]) + 1;
        A[i] = tempAry[randIdx];

        tempAry[randIdx] = tempAry[tempAry[0]--];
    }

    FREE(tempAry);   

    /* non-duplicated random array, slow */
/**     srand(time(NULL));
  * 
  *     for (i = 1; i <= A[0]; i++) {
  *         A[i] = (rand() % A[0]) + 1;
  * 
  *         for (j = 1; j < i; j++) {
  *             if(A[i] == A[j])
  *             {
  *                 i--;
  *                 break;
  *             }
  *         }
  *     }  */

  return A;
}


void DestroyRandomArray(int* A)
{
    if(A) FREE(A);
}

void PrintArray(int* A)
{
    int linecounter = 0;

    printf("----------------------- Printing Array -----------------------");
    for (int i = 1; i <= A[0]; ++i)
    {
        if(i % 10 == 1) printf("\nLine %d\t:", ++linecounter);
        printf("%4d ", A[i]);
    }
    putchar('\n');
    //printf("---------------------------- End -----------------------------\n");
}

int PrintMenu(void)
{
    int menu = 0;

    printf("---------------------------- Menu ----------------------------\n");
    printf("\t1. Insertion Sort\n");
    printf("\t2. Selection Sort\n");
    printf("\t3. Bubble Sort\n");
    printf("\t4. Heap Sort\n");
    printf("\t5. Merge Sort\n");
    printf("\t6. Quick Sort\n");
    printf("---------------------------- End -----------------------------\n");

    while(1)
    {
        char c = 0;
        
        printf("Select : "); scanf("%3d", &menu);
        while((c = getchar()) != '\n' && c != EOF);

        /** rewind(stdin); */

        if(menu < 1 || menu > 6) {
            printf(ANSI_COLOR_RED "********** Warning: Select integer between 1 and 6. **********\n"ANSI_COLOR_RESET);
            continue;
        }
        break;
    }
    return menu;
}

void ISort(int *A)
{
    InsertionSort(A);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void SSort(int *A)
{
    SelectionSort(A);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void BSort(int *A)
{
    BubbleSort(A);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void HSort(int *A)
{
    if(PRINTSORTING) {
        printf("before sorting\n");
        PrintArray(A);
        putchar('\n');
    }
    HeapSort(A);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void MSort(int *A)
{
    if(PRINTSORTING) {
        printf("before sorting\n");
        PrintArray(A);
    }
    MergeSort(A, 1, A[0]);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void QSort(int *A)
{
    if(PRINTSORTING) {
        printf("before sorting\n");
        PrintArray(A);
    }
    QuickSort(A, 1, A[0]);
    if(PRTASK) PrintAsterisks(A);
    if( PRINTSORTING == 0 ) {
        printf("\nsorted.\n");
        PrintArray(A);
    }
}
void swap(int* a, int* b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void PrintAsterisks(int *A)
{
    int i = 0, j = 0;

    for (j = 0; j < 30000000; j++) {
        
    }
    printf("\033c");

    //Print Rectangles
    if(RECTNOTASK) {
        for (i = 1; i <= A[0]; i++) {
            printf("A[%03d]: ", i);
            for (j = 1; j < A[i]; j++) {
                printf("◼︎");
            }
            printf("◼︎\n");
        }
    }
    //Print Asterisks
    else {
        for (i = A[0]; i > 0; i--) {
            printf("A[%03d]: ", i);
            for (j = 1; j < A[i]; j++) {
                putchar(' ');
            }
            printf("*\n");
        }
    }

}
